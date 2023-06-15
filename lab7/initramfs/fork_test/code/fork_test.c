#include "printf.h"
#include "uart.h"
#include "syscall.h"

void main(void) 
{
    init_printf(0, putc);
    printf("Fork Test, pid %d\n", getpid());

    int cnt = 1;
    int ret = 0;
    
    if ((ret = fork()) == 0) 
    {
        printf("pid: %d, cnt: %d, ptr: %x\n", getpid(), cnt, &cnt);
        ++cnt;

        fork();
        while (cnt < 5)
        {
            printf("pid: %d, cnt: %d, ptr: %x\n", getpid(), cnt, &cnt);
            ++cnt;
        }
        exit();
    }
    else 
    {
        printf("parent here, pid %d, child %d\n", getpid(), ret);
        exit();
    }
}
