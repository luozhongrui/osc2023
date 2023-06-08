# OSC2023

| Github Account | Student ID | Name         |
| -------------- | ---------- | ------------ |
| luozhongrui    | 0856151    | Luo Zhongrui |

## Requirements

- a cross-compiler for aarch64
- (optional) qemu-system-arm

## Build

```
make
```

## Test With QEMU

```
qemu-system-aarch64 -M raspi3b -kernel kernel.img -initrd initramfs.cpio -serial null -serial stdio -dtb bcm2710-rpi-3-b-plus.dtb
```

## Course Website

IOC5226: Operating System Capstone

https://oscapstone.github.io/

## Labs list

Lab0: Environment Setup

Lab1: Hello World

Lab2: Booting

Lab3: Exception and Interrupt

Lab4: Allocator

Lab5: Thread and User Process

Lab6: Virtual Memory

Lab7: Virtual File System

Lab8: Non-volatile Storage
