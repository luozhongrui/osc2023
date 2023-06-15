#include "syscall.h"

.global getpid
getpid:
    mov x8, SYS_GETPID
    svc 0
    ret

.global uart_read
uart_read:
    mov x8, SYS_UART_READ
    svc 0
    ret

.global uart_write
uart_write:
    mov x8, SYS_UART_WRITE
    svc 0
    ret

.global exec
exec:
    mov x8, SYS_EXEC
    svc 0
    ret

.global exit
exit:
    mov x8, SYS_EXIT
    svc 0
    ret

.global fork
fork:
    mov x8, SYS_FORK
    svc 0
    ret

.global schedule
schedule:
    mov x8, SYS_SCHEDULE
    svc 0
    ret

.global enable_core_timer
enable_core_timer:
    mov x8, SYS_ENABLE_CORE_TIMER
    svc 0
    ret

.global disable_core_timer
disable_core_timer:
    mov x8, SYS_DISABLE_CORE_TIMER
    svc 0
    ret

.global set_timeout
set_timeout:
    mov x8, SYS_SET_TIMEOUT
    svc 0
    ret

.global open
open:
    mov x8, SYS_OPEN
    svc 0
    ret

.global close
close:
    mov x8, SYS_CLOSE
    svc 0
    ret

.global read
read:
    mov x8, SYS_READ
    svc 0
    ret

.global write
write:
    mov x8, SYS_WRITE
    svc 0
    ret

.global read_directory
read_directory:
    mov x8, SYS_READ_DIRECTORY
    svc 0
    ret

.global make_directory
make_directory:
    mov x8, SYS_MAKE_DIRECTORY
    svc 0
    ret

.global change_directory
change_directory:
    mov x8, SYS_CHANGE_DIRECTORY
    svc 0
    ret

.global mount
mount:
    mov x8, SYS_MOUNT
    svc 0
    ret

.global unmount
unmount:
    mov x8, SYS_UNMOUNT
    svc 0
    ret
