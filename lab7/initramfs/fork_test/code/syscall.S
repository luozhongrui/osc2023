#include "syscall.h"

.global getpid
getpid:
    mov x8, SYS_GETPID
    svc 2
    ret

.global uart_read
uart_read:
    mov x8, SYS_UART_READ
    svc 2
    ret

.global uart_write
uart_write:
    mov x8, SYS_UART_WRITE
    svc 2
    ret

.global exec
exec:
    mov x8, SYS_EXEC
    svc 2
    ret

.global exit
exit:
    mov x8, SYS_EXIT
    svc 2
    ret

.global fork
fork:
    mov x8, SYS_FORK
    svc 2
    ret

.global schedule
schedule:
    mov x8, SYS_SCHEDULE
    svc 2
    ret

.global enable_core_timer
enable_core_timer:
    mov x8, SYS_ENABLE_CORE_TIMER
    svc 2
    ret

.global disable_core_timer
disable_core_timer:
    mov x8, SYS_DISABLE_CORE_TIMER
    svc 2
    ret

.global set_timeout
set_timeout:
    mov x8, SYS_SET_TIMEOUT
    svc 2
    ret
