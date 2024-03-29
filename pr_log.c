#include "pr_log.h"

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#ifndef PR_LOG_DISABLE

static int pr_log_ex_level_match(const char *module_name_filter, const char *module_name)
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
            if ((0 == strncasecmp(seq, module_name, seq_len)))
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

int pr_log_level(const char *module_name)
{
    int log_level = PR_LOG_DEFAULT_LEVEL;

    char *c = getenv("pr_log_level");
    if (c)
    {
        log_level = atoi(c);
    }

    if (0 == pr_log_ex_level_match(getenv("pr_log_level_ex_0"), module_name))
    {
        log_level = 0;
    }
    else if (0 == pr_log_ex_level_match(getenv("pr_log_level_ex_1"), module_name))
    {
        log_level = 1;
    }
    else if (0 == pr_log_ex_level_match(getenv("pr_log_level_ex_2"), module_name))
    {
        log_level = 2;
    }
    else if (0 == pr_log_ex_level_match(getenv("pr_log_level_ex_3"), module_name))
    {
        log_level = 3;
    }
    else if (0 == pr_log_ex_level_match(getenv("pr_log_level_ex_4"), module_name))
    {
        log_level = 4;
    }
    else if (0 == pr_log_ex_level_match(getenv("pr_log_level_ex_5"), module_name))
    {
        log_level = 5;
    }
    else if (0 == pr_log_ex_level_match(getenv("pr_log_level_ex_6"), module_name))
    {
        log_level = 6;
    }

    return log_level;
}

#endif
