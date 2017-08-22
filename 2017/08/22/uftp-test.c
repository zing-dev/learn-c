//
// Created by zhangrongxiang on 2017/8/22 11:18.
// Copyright (c) 2017 ZRX . All rights reserved.
//

/***************************************************************************/
/*****uftp*******/
typedef struct uftp_t uftp_t;
struct uftp_t {
    void (*print_usage)(uftp_t *this, char *program_name);
    void (*parse_conf) (uftp_t *this, int argc, char **argv);
    void (*single_app)(uftp_t *this); /* 单实例运行 */
    void (*daemon_app)(uftp_t *this); /* 后台运行 */
    void (*start) (uftp_t *this);
    void (*destroy) (uftp_t *this);
};
typedef struct private_uftp_t private_uftp_t;
struct private_uftp_t {
    uftp_t	public;
    uint32 daemon; /* 后台运行 */
    char *single_app_lock;
    udt_t *udt;
};
/***************************************************************************/



/***************************************************************************/
/**********udt***********/
typedef struct private_udt_t private_udt_t;
struct private_udt_t {
    udt_t	public;
    udp_t *udp; /* UDP传输通道 */
    msg_queue_t * msg_queue; /* 文件的消息队列 */
};
/***************************************************************************/



/***************************************************************************/
/******uftpd*******/
typedef struct uftpd_t uftpd_t;
struct uftpd_t {
    void (*print_usage)(uftpd_t *this, char *program_name);
    void (*parse_conf) (uftpd_t *this, int argc, char **argv);
    void (*single_app)(uftpd_t *this); /* 单实例运行 */
    void (*daemon_app)(uftpd_t *this); /* 后台运行 */
    void (*start) (uftpd_t *this);
    void (*destroy) (uftpd_t *this);
};
typedef struct private_uftpd_t private_uftpd_t;
struct private_uftpd_t {
    uftpd_t	public;
    uint32 daemon; /* 后台运行 */
    char *single_app_lock;
    udt_t *udt;
};

/***************************************************************************/


/***************************************************************************/
/******udt*****/
typedef struct private_udt_t private_udt_t;
struct private_udt_t {
    udt_t	public;
    ring_buffer_t *ring_buffer;
    udp_t *udp; /* UDP传输通道 */
    dispatch_t * dispatch; /* 根据tunnel查询文件名和文件句柄 */
    msg_queue_t * msg_queue; /* 文件处理的消息队列 */
};
//public
typedef struct udt_t udt_t;
struct udt_t {
    /* method "get" with one parameter and no return value */
    void (*recv_pkt_to_buff)(udt_t *this);
    /* method "put" with one parameters and no return value */
    void (*get_buff_and_process)(udt_t *this);
    /* method "destroy" with no parameters (except "this") and a return value */
    void (*destroy) (udt_t *this);
};

/****************************in***********************************************/
typedef struct main_app_t main_app_t;
struct main_app_t {
    void (*print_usage)(main_app_t *this, char *program_name);
    void (*parse_conf) (main_app_t *this, int argc, char **argv);
    void (*single_app)(main_app_t *this); /* 单实例运行 */
    void (*daemon_app)(main_app_t *this); /* 后台运行 */
    void (*start) (main_app_t *this);
    void (*destroy) (main_app_t *this);
};
typedef struct private_main_app_t private_main_app_t;
struct private_main_app_t {
    main_app_t	public;
    uint32 daemon; /* 后台运行 */
    char *single_app_lock;
    msg_queue_t * msg_queue; /* 文件的消息队列 */
};
/*************************out**************************************************/
typedef struct main_app_t main_app_t;
struct main_app_t {
    void (*print_usage)(main_app_t *this, char *program_name);
    void (*parse_conf) (main_app_t *this, int argc, char **argv);
    void (*single_app)(main_app_t *this); /* 单实例运行 */
    void (*daemon_app)(main_app_t *this); /* 后台运行 */
    void (*start) (main_app_t *this);
    void (*destroy) (main_app_t *this);
};
typedef struct private_main_app_t private_main_app_t;
struct private_main_app_t {
    main_app_t	public;
    uint32 daemon; /* 后台运行 */
    char *single_app_lock;
};
/***************************************************************************/