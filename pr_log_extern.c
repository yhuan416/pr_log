#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <time.h>

#ifndef CLOCK_MONOTONIC
#define CLOCK_MONOTONIC (1)
#endif

#define PR_LOG_OUT_BUF_SIZE (128)

void pr_log_extern(int logv, const char *_module_name, const char *fmt, ...)
{
    va_list va;
    struct timespec ts;
    int pid = syscall(SYS_gettid);
    clock_gettime(CLOCK_MONOTONIC, &ts);

    char pr_log_out_buf[PR_LOG_OUT_BUF_SIZE] = {0};

    va_start(va, fmt);
    vsnprintf(pr_log_out_buf, PR_LOG_OUT_BUF_SIZE, fmt, va);
    va_end(va);

    printf("<%d> [%010ld.%03ld][%04d][%s] %s\n", logv, ts.tv_sec, ts.tv_nsec / 1000000, pid, _module_name, pr_log_out_buf);
}
