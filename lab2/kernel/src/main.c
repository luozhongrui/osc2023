/*
 * Copyright (C) 2018 bzt (bztsrc@github)
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */

#include "uart.h"
#include "shell.h"
#include "cpio.h"
#include "dtb.h"
#include "utils.h"

void main(void *dtbAddress)
{
    // set up serial console
    uart_init();

    // say hello
    uart_puts("Hello World!\n");
    heapInit();
    // uart_hex(dtbAddress);
    uart_puts("\n");
    uart_puts("initrams(init): ");
    uart_hex(initrdGet());
    uart_puts("\n");
    fdt_find_do(dtbAddress, "linux,initrd-start", initrd_fdt_callback);
    uart_puts("initrams(loaded): ");
    uart_hex(initrdGet());
    uart_puts("\n");
    shellStart();
}
