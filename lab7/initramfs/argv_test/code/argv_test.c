#include "printf.h"
#include "uart.h"
#include "syscall.h"

void main(int argc, char **argv) 
{
    init_printf(0, putc);
    printf("Argv Test, pid %d\n", getpid());

    for (int i = 0; i < argc; i++)
        printf("%s ", argv[i]);
    printf("\n");
    
    const char *fork_argv[] = {"fork_test", 0};
    exec("fork_test.img", fork_argv);
}
