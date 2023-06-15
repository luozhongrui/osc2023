#include "uart1.h"
#include "shell.h"
#include "dtb.h"
#include "memory.h"
#include "exception.h"
#include "irqtask.h"
#include "timer.h"
#include "schedule.h"
#include "vfs.h"
#include "printf.h"

void main(char *arg)
{
    char input_buffer[CMD_MAX_LEN];

    dtb_ptr = PHYS_TO_VIRT(arg);
    traverse_device_tree(dtb_ptr, dtb_callback_initramfs); // get initramfs location from dtb
    uart_init();
    init_printf(0, putc);
    init_allocator();
    printf("Hello, world!\n");

    irqtask_init_list();
    printf("Hello, world!!\n");
    timer_list_init();
    printf("Hello, world!!\n");
    init_thread_sched();
    printf("Hello, world!!\n");

    init_rootfs();
    printf("Hello, world!!\n");
    uart_interrupt_enable();
    el1_interrupt_enable(); // enable interrupt in EL1 -> EL1
    core_timer_enable();
    printf("Hello, world!\n");

    while (1)
    {
        cli_cmd_clear(input_buffer, CMD_MAX_LEN);
        printf("# ");
        cli_cmd_read(input_buffer);
        cli_cmd_exec(input_buffer);
    }
}
