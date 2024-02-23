#include "pr_log.h"

#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <limits.h>

#define DEBUG_NEED_INIT INT_MIN
static int debug = DEBUG_NEED_INIT;

#ifndef PR_LOG_DISABLE
int pr_log_level(void)
{
    if (debug != DEBUG_NEED_INIT)
        return debug;

    char *c = getenv("pr_log_level");// pr_log_ex_level_0
    if (!c)
    {
        debug = PR_LOG_DEFAULT_LEVEL;
        return debug;
    }

    debug = atoi(c);
    return debug;
}
#endif

static inline bool debug_is(int lvl)
{
    return lvl <= pr_log_level();
}

void pr_log_impl(char const *fmt, ...)
{
    int level = INT_MIN;
    if (fmt[0] == '<' && isdigit(fmt[1]) && fmt[2] == '>')
        level = fmt[1] - '0';

    if (!debug_is(level))
        return;

    va_list va;
    va_start(va, fmt);
    vfprintf(stdout, fmt, va);
    va_end(va);
}
