SRCS 			= $(wildcard ./code/*.c)
OBJS			= $(SRCS:%.c=%.o)

PROGRAM			= vfs_test
ELF				= ./code/$(PROGRAM).elf
IMG				= ../$(PROGRAM).img

CFLAGS 			= -Wall -ffreestanding -nostdlib
CC 				= aarch64-linux-gnu-gcc
LINKER 			= aarch64-linux-gnu-ld
OBJ_COPY 		= aarch64-linux-gnu-objcopy

.PHONY: 		clean

all:			$(IMG)

$(IMG):			$(OBJS) code/syscall.o code/start.o
	$(LINKER) -nostdlib $(OBJS) code/syscall.o code/start.o -T link.ld -o $(ELF)
	$(OBJ_COPY) -O binary $(ELF) $@

code/start.o:	code/start.S
	$(CC) $(CFLAGS) -c $< -o $@

code/syscall.o:	code/syscall.S
	$(CC) $(CFLAGS) -c $< -o $@

code/%.o: 		code/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(OBJS) code/syscall.o code/start.o $(ELF) $(IMG) >/dev/null 2>/dev/null || true
	