#include <stdio.h>

#include "pr_log.h"

int main(int argc, char const *argv[])
{
    pr_emerg("pr_emerg %d %s", 1, "2");
    pr_alert("pr_alert %d %s", 1, "2");
    pr_crit("pr_crit %d 0x%x", 1, 0x2);
    pr_error("pr_error %d", 1);
    pr_warn("pr_warn %d", 1);
    pr_notice("pr_notice %d", 1);
    pr_info("pr_info %d", 1);
    pr_debug("pr_debug %d", 1);

    return 0;
}
