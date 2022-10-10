# Kernel
 A rudimentary linux-like kernel, built from scratch

## What this is
First of all, this **UNFINISHED** 

This Kernel is a standalone, scratch made kernel designed to run on x86. It is very simple and reminscent of basic linux.

Tested in VMBox, on a 64-bit linux base.

## Features
- Can show text, supports ASCII
- Can clear screen, controllable buffers
- Keyboard support! Can take basic keyboard input.

## How to build

To build this as a ISO follow the following steps
(ill make a cmake file soon, ik ik)

First lets Build the assembly file into a object file
```
$ nasm -f elf32 boot.asm -o boot.o
```

Build Kernel.C into a object

```
$ gcc -m32 -c kernel.c -o kernel.o
```

Build keyboard.c and source.c
```
$ gcc -m32 -c keyboard.c -o keyboard.o
$ gcc -m32 -c source.c -o source.o
```
Link everything into one executable
```
$ ld -m elf_i386 -T linker.ld -o kernel boot.o kernel.o keyboard.o source.o
```
### Build the .iso

```
mkdir -p iso/boot/grub
cp kernel iso/boot/
cp grub.cfg iso/boot/grub/
grub-mkrescue -o my-kernel.iso iso/
```

### Test with qemu
```
qemu-system-x86_64 -boot d -cdrom my-kernel.iso -m 512
```

