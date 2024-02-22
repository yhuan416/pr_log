#ifndef _PR_lOG_H_
#define _PR_lOG_H_

#ifndef PR_LOG_DEFAULT_LEVEL
#define PR_LOG_DEFAULT_LEVEL    (6)
#endif

#define LOG_EMERG   "<0>"
#define LOG_ALERT   "<1>"
#define LOG_CRIT    "<2>"
#define LOG_ERROR   "<3>"
#define LOG_WARN    "<4>"
#define LOG_NOTICE  "<5>"
#define LOG_INFO    "<6>"
#define LOG_DEBUG   "<7>"

#define pr_emerg(...)   pr_log_(LOG_EMERG,  __VA_ARGS__)
#define pr_alert(...)   pr_log_(LOG_ALERT,  __VA_ARGS__)
#define pr_crit(...)    pr_log_(LOG_CRIT,   __VA_ARGS__)
#define pr_error(...)   pr_log_(LOG_ERROR,  __VA_ARGS__)
#define pr_warn(...)    pr_log_(LOG_WARN,   __VA_ARGS__)
#define pr_notice(...)  pr_log_(LOG_NOTICE, __VA_ARGS__)
#define pr_info(...)    pr_log_(LOG_INFO,   __VA_ARGS__)
#define pr_debug(...)   pr_log_(LOG_DEBUG,  __VA_ARGS__)

#ifndef PR_LOG_DISABLE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <time.h>

#ifndef CLOCK_MONOTONIC
#define CLOCK_MONOTONIC (1)
#endif

#define PRINTF_FMT(a, b) \
    __attribute__((format(printf, a, b)))

#define pr_log_(lvl, fmt, args...)                               \
    do {                                                    \
        struct timespec ts;                                 \
        int pid = syscall(SYS_gettid);                      \
        clock_gettime(CLOCK_MONOTONIC, &ts);                \
        pr_log_impl(lvl " [%010ld.%03ld][%04d] %s:%d/%s()\t" fmt "\n", \
               ts.tv_sec, ts.tv_nsec / 1000000, pid,        \
               __FILE__, __LINE__, __func__, ##args);       \
    } while (0)

extern int pr_log_level(void);
extern void PRINTF_FMT(1, 2) pr_log_impl(char const *fmt, ...);

#else

#define pr_log_level() (-1)
#define pr_log_(fmt, args...)

#endif

#endif
