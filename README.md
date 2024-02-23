# pr_log

## 等级

| OFF | FATAL | ERROR | WARN | INFO | DEBUG | TRACE |
| --- | --- | --- | --- | --- | --- | --- |
| 0 | 1 | 2 | 3 | 4 | 5 | 6 |

## 使用方法
``` c
#include <stdio.h>

// 定义模块名
#define module_name "main"
#include "pr_log.h"

int main(int argc, char const *argv[])
{
// 宏定义
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
```

## 日志格式

``` sh
<1> [0000234532.314][1438553][main] main(1,0x7ffca8d674f8)      pr_fatal 1
<日志等级> [时间戳][tid][模块名] ${func_format_s}\t${log}
```

## 修改打印等级

1. 构建时修改默认打印等级
``` sh
添加宏 -DPR_LOG_DEFAULT_LEVEL=0 [0 - 6]

> ./test/demo
<1> [0000235275.825][1444070][main] main(1,0x7ffeb0d2ea78)      pr_fatal 1
<2> [0000235275.825][1444070][main] main(1,0x7ffeb0d2ea78)      pr_error 2
<3> [0000235275.825][1444070][main] main(1,0x7ffeb0d2ea78)      pr_warn 3
<1> [0000235275.825][1444070][mod1] mod1_say_hello(0)   pr_fatal 0
<2> [0000235275.825][1444070][mod1] mod1_say_hello(0)   pr_error 0
<3> [0000235275.825][1444070][mod1] mod1_say_hello(0)   pr_warn 0
```

2. 运行时通过环境变量修改打印等级
``` sh
export pr_log_level=0 [0 - 6]

> pr_log_level=5 ./test/demo
<1> [0000235263.302][1443984][main] main(1,0x7ffffa8428d8)      pr_fatal 1
<2> [0000235263.302][1443984][main] main(1,0x7ffffa8428d8)      pr_error 2
<3> [0000235263.302][1443984][main] main(1,0x7ffffa8428d8)      pr_warn 3
<4> [0000235263.302][1443984][main] main(1,0x7ffffa8428d8)      pr_info 4
<5> [0000235263.302][1443984][main] main(1,0x7ffffa8428d8)      pr_debug 5
<1> [0000235263.302][1443984][mod1] mod1_say_hello(0)   pr_fatal 0
<2> [0000235263.302][1443984][mod1] mod1_say_hello(0)   pr_error 0
<3> [0000235263.302][1443984][mod1] mod1_say_hello(0)   pr_warn 0
<4> [0000235263.302][1443984][mod1] mod1_say_hello(0)   pr_info 0
<5> [0000235263.302][1443984][mod1] mod1_say_hello(0)   pr_debug 0
```

3. 运行时制定模块的打印等级
``` sh
> pr_log_level=5 pr_log_level_ex_1=main pr_log_level_ex_4=mod1 ./test/demo
<1> [0000235239.258][1443803][main] main(1,0x7ffd6337c2a8)      pr_fatal 1
<1> [0000235239.258][1443803][mod1] mod1_say_hello(0)   pr_fatal 0
<2> [0000235239.258][1443803][mod1] mod1_say_hello(0)   pr_error 0
<3> [0000235239.258][1443803][mod1] mod1_say_hello(0)   pr_warn 0
<4> [0000235239.258][1443803][mod1] mod1_say_hello(0)   pr_info 0
```

## 关闭打印

``` sh
添加宏 -DPR_LOG_DISABLE
```
