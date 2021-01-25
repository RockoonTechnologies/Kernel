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

Build Keyboard.C and Source.C
```
$ gcc -m32 -c Keyboard.c -o Keyboard.o
$ gcc -m32 -c Source.c -o Source.o
```
Link everything into one executable
```
$ ld -m elf_i386 -T linker.ld -o kernel boot.o kernel.o Keyboard.o Source.o
```
### Build the .iso

```
mkdir -p iso/boot/grub
cp kernel iso/boot/
cp grub.cfg iso/boot/grub/
grub-mkrescue -o my-kernel.iso iso/
```
