/*
 * 11.11
 *
 * mofaph@gmail.com
 * 2013-6-4
 *
 * unix> cc -Wall -I../../common ../../common/csapp.c tiny.c -lpthread -o tiny
 */

#include "csapp.h"

#include <limits.h>             /* INT_MIN */

void doit(int fd);

int parse_uri(char *uri, char *filename, char *cgiargs);

void serve_static(int fd, char *filename, int filesize, char *method);

void get_filetype(char *filename, char *filetype);

void serve_dynamic(int fd, char *filename, char *cgiargs, char *method);

void clienterror(int fd, char *cause, char *errnum,
                 char *shortmsg, char *longmsg);

void reap_child(int signo) {
    for (;;) {
        /* We don't care child's status */
        int ret = waitpid(-1, NULL, WNOHANG);
        if (ret == 0) /* child didn't terminated, return immediately */
            break;
        else if (ret < 0 && errno == ECHILD) /* no child */
            break;
        else
            /* continue */;
    }
}

static int is_wait;         /* Waits for child when failed to install handler */

int main(int argc, char **argv) {
    int listenfd, connfd, port;
    struct sockaddr_in clientaddr;
    socklen_t clientlen;    /* avoid compiler warning */

    /* Check command line args */
    if (argc != 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(1);
    }
    port = atoi(argv[1]);

    /* Install SIGCHILD handler */
    struct sigaction action, old_action;
    action.sa_handler = reap_child;
    sigemptyset(&action.sa_mask);
    action.sa_flags = SA_RESTART;
    int ret = sigaction(SIGCHLD, &action, &old_action);
    is_wait = ret < 0;
    if (is_wait) {
        fprintf(stderr,
                "sigaction: %s, we will wait child to terminated\n",
                strerror(errno));
    }

    listenfd = Open_listenfd(port);
    while (1) {
        clientlen = sizeof(clientaddr);
        connfd = Accept(listenfd, (SA * ) & clientaddr, &clientlen);
        doit(connfd);
        Close(connfd);
    }
}

/* Return a pointer to request, the caller should free the buffer */
char *read_request(rio_t *rp) {
    char buf[MAXLINE];
    char *request = NULL;

    for (;;) {
        Rio_readlineb(rp, buf, MAXLINE);
        /*
         * Firefox will sent \x16\x3.
         * \x16: Synchronous Idle, \x3: End of Text
         */
        if (!strncmp(buf, "\x16\x3", 2)) {
            free(request);
            return NULL;
        }
        int buflen = strlen(buf);
        char *old_request = request;
        int old_reqlen = old_request == NULL ? 0 : strlen(old_request);
        request = realloc(old_request, buflen + old_reqlen + 1);
        if (request == NULL) {
            fprintf(stderr, "realloc: run out of memory\n");
            free(old_request);
            return NULL;
        }
        memmove(request + old_reqlen, buf, buflen + 1);
        if (!strcmp(buf, "\r\n")) /* Copy before stop */
            break;
    }

    return request;
}

void write_to_file(char *request) {
    if (request == NULL)
        return;

    FILE *out = fopen("tiny-request.txt", "w+");
    if (out == NULL) {
        perror("fopen");
    } else {
        fprintf(out, "%s", request);
        fflush(out);
        fclose(out);
    }
}

void doit(int fd) {
    rio_t rio;
    Rio_readinitb(&rio, fd);
    char *request = read_request(&rio);
    if (request == NULL)
        return;
    write_to_file(request);

    char method[MAXLINE], uri[MAXLINE], version[MAXLINE];
    sscanf(request, "%s %s %s", method, uri, version);
    free(request);
    if (strcasecmp(method, "GET") && strcasecmp(method, "HEAD")) {
        clienterror(fd, method, "501", "Not implemented", "Tiny does not implement this method");
        return;
    }

    char filename[MAXLINE], cgiargs[MAXLINE];
    int is_static = parse_uri(uri, filename, cgiargs);
    struct stat sbuf;
    if (stat(filename, &sbuf) < 0) {
        clienterror(fd, filename, "404", "Not found", "Tiny couldn't read the file");
        return;
    }

    if (is_static) {        /* Serve static content */
        if (!(S_ISREG(sbuf.st_mode)) || !(S_IRUSR & sbuf.st_mode)) {
            clienterror(fd, filename, "403", "Forbidden", "Tiny couldn't read the filetype");
            return;
        }
        serve_static(fd, filename, sbuf.st_size, method);
    } else {                  /* Serve dynamic content */
        if (!(S_ISREG(sbuf.st_mode)) || !(S_IXUSR & sbuf.st_mode)) {
            clienterror(fd, filename, "403", "Forbidden", "Tiny couldn't run the CGI program");
            return;
        }
        serve_dynamic(fd, filename, cgiargs, method);
    }
}

void clienterror(int fd, char *cause, char *errnum,
                 char *shortmsg, char *longmsg) {
    char buf[MAXLINE], body[MAXBUF];

    /* Build the HTTP response body */
    snprintf(body, sizeof(body), "<html><title>Tiny Error</title>");
    snprintf(body, sizeof(body), "%s<body bgcolor=""ffffff"">\r\n", body);
    snprintf(body, sizeof(body), "%s%s: %s\r\n", body, errnum, shortmsg);
    snprintf(body, sizeof(body), "%s<p>%s: %s\r\n", body, longmsg, cause);
    snprintf(body, sizeof(body), "%s<hr><em>The Tiny Web server</em>\r\n", body);

    /* Print the HTTP response */
    snprintf(buf, sizeof(buf), "HTTP/1.0 %s %s\r\n", errnum, shortmsg);
    Rio_writen(fd, buf, strlen(buf));
    snprintf(buf, sizeof(buf), "Content-type: text/html\r\n");
    Rio_writen(fd, buf, strlen(buf));
    snprintf(buf, sizeof(buf), "Content-length: %d\r\n\r\n", (int) strlen(body));
    Rio_writen(fd, buf, strlen(buf));
    Rio_writen(fd, body, strlen(body));
}

int parse_uri(char *uri, char *filename, char *cgiargs) {
    char *ptr;

    if (!strstr(uri, "cgi-bin")) { /* Static content */
        strcpy(cgiargs, "");
        strcpy(filename, ".");
        strcat(filename, uri);
        if (uri[strlen(uri) - 1] == '/')
            strcat(filename, "home.html");
        return 1;
    } else {                /* Dynamic content */
        ptr = strchr(uri, '?');
        if (ptr) {
            strcpy(cgiargs, ptr + 1);
            *ptr = '\0';
        } else {
            strcpy(cgiargs, "");
        }
        strcpy(filename, ".");
        strcat(filename, uri);
        return 0;
    }
}

void send_response_body(int fd, char *filename) {
    /*
     * Send response body to client
     *
     * If the file is big enough, we read many times, and each time we
     * double increase buffer.
     */
    int srcfd = Open(filename, O_RDONLY, 0);
    char *body = NULL;
    const int min_size = (1 << 10); /* 1KB */
    int max_size = (unsigned) INT_MIN >> 1; /* 16bit: 16KB, 32bit: 1GB */
    size_t size = min_size;
    for (;;) {
        if (size != max_size) {
            char *old_body = body;
            body = realloc(old_body, size);
            if (body == NULL) {
                if (size == min_size) {
                    free(old_body);
                    perror("realloc");
                    break;
                } else { /* size > min_size */
                    max_size = size >> 1;
                    size = max_size;
                    body = old_body;
                }
            }
        }
        int n = Rio_readn(srcfd, body, size);
        if (n > 0)      /* read something */
            Rio_writen(fd, body, n);
        if (n != size)  /* EOF or read all the content */
            break;
        if (size != max_size)
            size <<= 1; /* increase buffer, read more next time */
    }

    /* Clean */
    free(body);
    Close(srcfd);
}

void serve_static(int fd, char *filename, int filesize, char *method) {
    char filetype[MAXLINE], buf[MAXBUF];

    /* Send response headers to client */
    get_filetype(filename, filetype);
    snprintf(buf, sizeof(buf), "HTTP/1.0 200 OK\r\n");
    snprintf(buf + strlen(buf), sizeof(buf) - strlen(buf), "Server: Tiny Web Server\r\n");
    snprintf(buf + strlen(buf), sizeof(buf) - strlen(buf), "Content-length: %d\r\n", filesize);
    snprintf(buf + strlen(buf), sizeof(buf) - strlen(buf), "Content-type: %s\r\n\r\n", filetype);
    Rio_writen(fd, buf, strlen(buf));

    if (!strcasecmp(method, "HEAD"))
        return;
    send_response_body(fd, filename);
}

/*
 * get_filetype - derive file type from name
 */
void get_filetype(char *filename, char *filetype) {
    if (strstr(filename, ".html"))
        strcpy(filetype, "text/html");
    else if (strstr(filename, ".gif"))
        strcpy(filetype, "image/gif");
    else if (strstr(filename, ".jpg"))
        strcpy(filetype, "image/jpeg");
    else if (strstr(filename, ".mpg"))
        strcpy(filetype, "video/mpeg");
    else
        strcpy(filetype, "text/plain");
}

void serve_dynamic(int fd, char *filename, char *cgiargs, char *method) {
    char buf[MAXLINE], *emptylist[] = {NULL};

    /* Return first part of HTTP response */
    snprintf(buf, sizeof(buf), "HTTP/1.0 200 OK\r\n");
    Rio_writen(fd, buf, strlen(buf));
    snprintf(buf, sizeof(buf), "Server: Tiny Web Server\r\n");
    Rio_writen(fd, buf, strlen(buf));

    if (Fork() == 0) {      /* child */
        /* Real server would set all CGI vars here */
        setenv("QUERY_STRING", cgiargs, 1);
        setenv("REQUEST_METHOD", method, 1);
        Dup2(fd, STDOUT_FILENO); /* Redirect stdout to client */
        Execve(filename, emptylist, environ); /* Run CGI program */
    }

    if (is_wait)
        Wait(NULL);     /* Parent waits for and reaps child */
}
