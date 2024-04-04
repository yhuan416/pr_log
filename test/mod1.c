#include <stdio.h>

#define mmodule_name "mod1"
#include "pr_log.h"

int mod1_say_hello(int i)
{
#undef func_format_s
#undef func_format
#define func_format_s "mod1_say_hello(%d)"
#define func_format() i

    pr_fatal("pr_fatal %d", i);
    pr_error("pr_error %d", i);
    pr_warn("pr_warn %d", i);
    pr_info("pr_info %d", i);
    pr_debug("pr_debug %d", i);
    pr_verbose("pr_verbose %d", i);

    return 0;
}
