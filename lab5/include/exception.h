#ifndef EXCEPTION_H
#define EXCEPTION_H

#define TRAPFRAME_SIZE 272

struct trapframe
{
    unsigned long x[31];    // general register from x0 ~ x30
    unsigned long sp_el0;   // user stack pointer
    unsigned long elr_el1;  // user program counter
    unsigned long spsr_el1; // user cpsr
};

void enable_irq();
void disable_irq();

void return_to_user_code();

#endif