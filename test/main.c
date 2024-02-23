#include <stdio.h>

#define module_name "main"
#include "pr_log.h"

int main(int argc, char const *argv[])
{
#undef func_format_s
#undef func_format
#define func_format_s "main(%d,%p)"
#define func_format() argc, argv

    pr_fatal("pr_fatal %d", 1);
    pr_error("pr_error %d", 2);
    pr_warn("pr_warn %d", 3);
    pr_info("pr_info %d", 4);
    pr_debug("pr_debug %d", 5);
    pr_trace("pr_trace %d", 6);

    return 0;
}
