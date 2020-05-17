//
// Created by zhangrongxiang on 2018/1/11 14:51
// File uftp
//

#define INIT(this, ...) { /*(this) = malloc(sizeof(*(this)));*/ \
                                                   *(this) = (typeof(*(this))){ __VA_ARGS__ }; }
#define METHOD(iface, name, ret, this, ...) \
        static ret name(union {iface *_public; this;} \
        __attribute__((transparent_union)), ##__VA_ARGS__); \
        static typeof(name) *_##name = (typeof(name)*)name; \
        static ret name(this, ##__VA_ARGS__)

typedef short int int16;
typedef unsigned short int uint16;

typedef int int32;
typedef unsigned int uint32;

typedef long long int64;
typedef unsigned long long uint64;


typedef struct udt_t udt_t;

struct udt_t {
    /* method "get" with one parameter and no return value */
    void (*recv_pkt_to_buff)(udt_t *this);

    /* method "put" with one parameters and no return value */
    void (*get_buff_and_process)(udt_t *this);

    /* method "destroy" with no parameters (except "this") and a return value */
    void (*destroy)(udt_t *this);
};

/////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct uftpd_t uftpd_t;

struct uftpd_t {

    void (*print_usage)(uftpd_t *this, char *program_name);

    void (*parse_conf)(uftpd_t *this, int argc, char **argv);

    void (*single_app)(uftpd_t *this); /* 单实例运行 */

    void (*daemon_app)(uftpd_t *this); /* 后台运行 */

    void (*start)(uftpd_t *this);

    void (*destroy)(uftpd_t *this);
};
/////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct private_uftpd_t private_uftpd_t;

struct private_uftpd_t {
    uftpd_t public;
    uint32 daemon; /* 后台运行 */
    char *single_app_lock;
    udt_t *udt;
};

uftpd_t *uftpd_create(void) {
    private_uftpd_t *this;
    INIT(this, {});

    /* return public part */
    return &this->public;
}

METHOD(uftpd_t, start, void,
       private_uftpd_t *this)
{
}

int main(int argc, char **argv) {
    uftpd_t *uftpd = uftpd_create();

    uftpd->parse_conf(uftpd, argc, argv);

#ifndef DEBUG_PRINT
    uftpd->single_app(uftpd);
#endif

    uftpd->daemon_app(uftpd);

    uftpd->start(uftpd);

    uftpd->destroy(uftpd);

    return 0;
}

