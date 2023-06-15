#include "uart1.h"
#include "shell.h"
#include "dtb.h"
#include "memory.h"
#include "exception.h"
#include "irqtask.h"
#include "timer.h"
#include "schedule.h"
#include "vfs.h"

void main(char *arg)
{
    char input_buffer[CMD_MAX_LEN];

    dtb_ptr = PHYS_TO_VIRT(arg);
    traverse_device_tree(dtb_ptr, dtb_callback_initramfs); // get initramfs location from dtb

    init_allocator();

    uart_init();
    irqtask_init_list();
    uart_puts("Hello world!\n ");
    timer_list_init();
    uart_puts("Hello world!\n ");
    init_thread_sched();
    uart_puts("Hello world!\n ");
    init_rootfs();
    uart_puts("Hello world!\n ");
    uart_interrupt_enable();
    uart_puts("Hello world!\n ");
    el1_interrupt_enable(); // enable interrupt in EL1 -> EL1
    uart_puts("Hello world!\n ");
    core_timer_enable();
    uart_puts("Hello world!\n ");

#if DEBUG
    cli_cmd_read(input_buffer); // Wait for input, Windows cannot attach to SERIAL from two processes.
#endif

    // cli_print_banner();
    while (1)
    {
        cli_cmd_clear(input_buffer, CMD_MAX_LEN);
        uart_puts("# ");
        cli_cmd_read(input_buffer);
        cli_cmd_exec(input_buffer);
    }
}
