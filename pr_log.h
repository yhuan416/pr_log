#ifndef _PR_lOG_H_
#define _PR_lOG_H_

#ifndef PR_LOG_DEFAULT_LEVEL
#define PR_LOG_DEFAULT_LEVEL (3)
#endif

#define LOG_FATAL (1)
#define LOG_ERROR (2)
#define LOG_WARN (3)
#define LOG_INFO (4)
#define LOG_DEBUG (5)
#define LOG_TRACE (6)

#if PR_LOG_DEFAULT_LEVEL >= LOG_FATAL
#define pr_fatal(...) pr_log_(LOG_FATAL, __VA_ARGS__)
#else
#define pr_fatal(...)
#endif

#if PR_LOG_DEFAULT_LEVEL >= LOG_ERROR
#define pr_error(...) pr_log_(LOG_ERROR, __VA_ARGS__)
#else
#define pr_error(...)
#endif

#if PR_LOG_DEFAULT_LEVEL >= LOG_WARN
#define pr_warn(...) pr_log_(LOG_WARN, __VA_ARGS__)
#else
#define pr_warn(...)
#endif

#if PR_LOG_DEFAULT_LEVEL >= LOG_INFO
#define pr_info(...) pr_log_(LOG_INFO, __VA_ARGS__)
#else
#define pr_info(...)
#endif

#if PR_LOG_DEFAULT_LEVEL >= LOG_DEBUG
#define pr_debug(...) pr_log_(LOG_DEBUG, __VA_ARGS__)
#else
#define pr_debug(...)
#endif

#if PR_LOG_DEFAULT_LEVEL >= LOG_TRACE
#define pr_trace(...) pr_log_(LOG_TRACE, __VA_ARGS__)
#else
#define pr_trace(...)
#endif

#ifndef PR_LOG_DISABLE

#include <stdio.h>

#define PRINTF_FMT(a, b) \
    __attribute__((format(printf, a, b)))

#if !defined(mmodule_name)
#define mmodule_name "unknown"
#endif

#if !defined(func_format)
#define func_format_s "(%s)"
#define func_format() "..."
#endif

extern int pr_log_level(const char *module_name);
extern void PRINTF_FMT(3, 4) pr_log_extern(int logv, const char *module_name, const char *fmt, ...);

static long pr_log_level_extern(void)
{
#define NEED_INIT (-1)
    static long pr_log_level_local = NEED_INIT;
    if (pr_log_level_local == NEED_INIT)
    {
        pr_log_level_local = pr_log_level(mmodule_name);
    }
    return pr_log_level_local;
}

#define pr_log_(logv, fmt, args...)                              \
    do                                                           \
    {                                                            \
        if (logv > pr_log_level_extern())                        \
            break;                                               \
        pr_log_extern(logv, mmodule_name, func_format_s "\t" fmt, \
                      func_format(), ##args);                    \
    } while (0)

#else
#define pr_log_level(_module_name) (-1)
#define pr_log_(fmt, args...)
#endif

#endif
