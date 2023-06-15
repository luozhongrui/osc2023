#ifndef SYSCALL_INTERNAL_H
#define SYSCALL_INTERNAL_H

#define SYS_GETPID 0
#define SYS_UART_READ 1
#define SYS_UART_WRITE 2
#define SYS_EXEC 3
#define SYS_FORK 4
#define SYS_EXIT 5
#define SYS_MBOX_CALL 6
#define SYS_KILL 7
#define SYS_SIGNAL 8
#define SYS_POSIX_KILL 9
#define SYS_SCHEDULE 10
#define SYS_OPEN 11
#define SYS_CLOSE 12

#define SYS_WRITE 13
#define SYS_READ 14
#define SYS_MAKE_DIRECTORY 15
#define SYS_MOUNT 16

#define SYS_CHANGE_DIRECTORY 17

#define SYS_READ_DIRECTORY 20
#define SYS_UNMOUNT 21
#define SYS_ENABLE_CORE_TIMER 22
#define SYS_DISABLE_CORE_TIMER 23
#define SYS_SET_TIMEOUT 24

#ifndef __ASSEMBLER__

/* for user program */
int getpid();
unsigned int uart_read(char buf[], unsigned int size);
unsigned int uart_write(char buf[], unsigned int size);
int exec(char *program_name, const char *argv[]);
void exit();
int fork();
void schedule();
void enable_core_timer();
void disable_core_timer();
void set_timeout(int second, const char *message);
int open(char *path_name, int flags);
int close(int fd);
int write(int fd, void *buffer, int length);
int read(int fd, void *buffer, int length);
char **read_directory(int fd);
int make_directory(char *path_name);
int change_directory(char *path_name);
int mount(char *device, char *mounting_point, char *filesystem);
int unmount(char *mounting_point);



#endif

#endif