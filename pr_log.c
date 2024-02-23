#include "pr_log.h"

#include <stdio.h>
#include <strings.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <limits.h>

#ifndef PR_LOG_DISABLE

int pr_log_ex_level_match(const char *module_name_filter, const char *_module_name)
{
    unsigned long seq_len;
    char *seq, *value = (char *)module_name_filter;
    if (NULL == value)
    {
        return -1;
    }
    while (*value)
    {
        while ((',' == *value) || (';' == *value) || (' ' == *value) || ('\t' == *value))
        {
            ++value;
        };
        seq = value;
        for (seq_len = 0; ((0 != seq[seq_len]) && (',' != seq[seq_len]) && (';' != seq[seq_len]) && (' ' != seq[seq_len]) && ('\t' != seq[seq_len])); ++seq_len)
        {
        };
        if (seq_len)
        {
            if ((0 == strncasecmp(seq, _module_name, seq_len)))
            {
                return 0;
            }
        }
        value += seq_len;
        if (*value)
        {
            ++value; /* skip seq */
        };
    }
    return -1;
}

int pr_log_level(const char *_module_name)
{
    int log_level = PR_LOG_DEFAULT_LEVEL;

    char *c = getenv("pr_log_level");
    if (c)
    {
        log_level = atoi(c);
    }

    if (0 == pr_log_ex_level_match(getenv("pr_log_level_ex_0"), _module_name))
    {
        log_level = 0;
    }
    else if (0 == pr_log_ex_level_match(getenv("pr_log_level_ex_1"), _module_name))
    {
        log_level = 1;
    }
    else if (0 == pr_log_ex_level_match(getenv("pr_log_level_ex_2"), _module_name))
    {
        log_level = 2;
    }
    else if (0 == pr_log_ex_level_match(getenv("pr_log_level_ex_3"), _module_name))
    {
        log_level = 3;
    }
    else if (0 == pr_log_ex_level_match(getenv("pr_log_level_ex_4"), _module_name))
    {
        log_level = 4;
    }
    else if (0 == pr_log_ex_level_match(getenv("pr_log_level_ex_5"), _module_name))
    {
        log_level = 5;
    }
    else if (0 == pr_log_ex_level_match(getenv("pr_log_level_ex_6"), _module_name))
    {
        log_level = 6;
    }

    return log_level;
}
#endif

void pr_log_impl(char const *fmt, ...)
{
    va_list va;
    va_start(va, fmt);
    vfprintf(stdout, fmt, va);
    va_end(va);
}
