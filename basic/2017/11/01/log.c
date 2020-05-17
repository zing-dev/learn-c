//
// Created by zhangrongxiang on 2017/11/1 11:31
// File log
//

#include <syslog.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void createLog();

/**
 *
 * /var/log/messages 包含所有的系统消息
 * /var/log/mail 包含来自邮件系统的其它日志消息
 * /var/log/debug 可能包含调试消息。
 *
 * /etc/syslog.conf 或者 /etc/syslog-ng/syslog-ng.conf 文件系统(消息)配置情况。
 *
 * LOG_EMERG          紧急状况 --> terminal (Message from syslogd@debian at Nov  1 14:28:18 ...)
 * LOG_ALERT          高优先级故障，如数据库损坏 --> /var/log/syslog
 * LOG_CRIT           关键性(critical)错误，如硬件操作失败 --> /var/log/syslog
 * LOG_ERR            一般错误 --> /var/log/syslog
 * LOG_WARNING        一般警告 --> /var/log/message
 * LOG_NOTICE         需要注意的特殊条件 --> /var/log/message
 * LOG_INFO           通知性消息(Information messages) --> /var/log/message
 * LOG_DEBUG          调试消息 --> /var/log/debug
 *
 * 消息标题(message header)和消息内容(message body)组成。
 * 消息标题由设备指示符(facility indicator)、日期和时间创建
 * 消息内容由message 参数生成
 *
 *
 * @return
 */
int main() {
    int i = 0;
    while (i++ < 100) {
        createLog();
    }
    exit(0);
}

void createLog() {
    int logmask;
//    /var/log/message
    openlog("logmask", LOG_PID | LOG_CONS, LOG_USER);
//    syslog(LOG_INFO, "informative message, pid = %d", getpid());
//    syslog(LOG_INFO, "informative message, pid = %d log_level = %d\n", getpid(), LOG_INFO);
    /// void syslog(int priority, const char *message, arguments...);
    syslog(LOG_NOTICE, "informative message, pid = %d log_level = %d\n", getpid(), LOG_NOTICE);
//    syslog(LOG_ERR, "informative message, pid = %d log_level = %d\n", getpid(), LOG_ERR);
//    syslog(LOG_DEBUG, "debug message, should appear");
//    logmask = setlogmask(LOG_UPTO(LOG_NOTICE));
//    syslog(LOG_DEBUG, "debug message, should not appear");
    sleep(1);
}
/**
 *
 * void syslog(int priority, const char *message, arguments...);
 *
 * 改变日志消息的呈现方式
 * void openlog(const char *ident, int logopt, int facility);
 *
 * LOG_PID            加上进程标识符(系统分配给每个进程的一个独一无二的数字标识)
 * LOG_CONS           如果消息无法记录到日志文件里则发送消息到控制台
 * LOG_NDELAY         在第一次调用 syslog 函数时打开日志功能
 * LOG_NDELAY         立即打开日志功能，而不等到第一次记日志时
 *
 * void closelog(void);
 *
 * 设置日志掩码,可以控制日志消息的优先级
 * int setlogmask(int maskpri);
 *
 */
