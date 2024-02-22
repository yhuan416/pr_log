#include <stdio.h>

#include "pr_log.h"

int main(int argc, char const *argv[])
{
    pr_fatal("pr_fatal %d", 1);
    pr_error("pr_error %d", 2);
    pr_warn("pr_warn %d", 3);
    pr_info("pr_info %d", 4);
    pr_debug("pr_debug %d", 5);
    pr_trace("pr_trace %d", 6);

    return 0;
}
