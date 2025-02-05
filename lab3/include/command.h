#ifndef COMMAND_H
#define COMMAND_H

void input_buffer_overflow_message(char[]);

void command_help();
void command_hello();
void command_not_found(char *);
void command_show_el();
void command_ls();
void command_cat();
void command_run();
void command_timer_on();
void command_timer_off();
void command_set_timeout();
void command_reboot();

#endif