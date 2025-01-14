SRCS = $(wildcard ./src/*.c)
OBJS := $(addprefix ./build/, $(notdir $(SRCS:.c=.o)))
OBJS += ./build/start.o

INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = build

CFLAGS = -Wall -O2 -ffreestanding -MMD -MP -static
CC = aarch64-none-elf-gcc
LINKER = aarch64-none-elf-ld
OBJ_CPY = aarch64-none-elf-objcopy

.PHONY: clean run deploy

all: kernel8.img

$(OBJ_DIR)/start.o: $(SRC_DIR)/start.S
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

kernel8.img: $(OBJS) link.ld
	$(LINKER) -nostdlib $(OBJS) -T link.ld -o kernel8.elf
	$(OBJ_CPY) -O binary kernel8.elf kernel8.img

clean:
	rm kernel8.elf kernel8.img build/*.o >/dev/null 2>/dev/null || true

deploy: all
	cp ./kernel8.img /Volumes/NO\ NAME
	diskutil eject /Volumes/NO\ NAME

run: all
	qemu-system-aarch64 -M raspi3 -kernel kernel8.img -serial null -serial stdio -display none -initrd initramfs.cpio -dtb bcm2710-rpi-3-b-plus.dtb

pty:
	qemu-system-aarch64 -M raspi3b -kernel kernel8.img -initrd initramfs.cpio -serial null -serial pty -display none

debug:
	qemu-system-aarch64 -M raspi3b -kernel kernel8.img -initrd initramfs.cpio -serial null  -display none  -initrd initramfs.cpio -dtb bcm2710-rpi-3-b -S -s
