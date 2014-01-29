SOURCES=boot.o kernel_main.o string.o term.o util.o gdt.o idt.o isr.o interrupt.o gdt-as.o panic.o clock.o keyboard.o heap.o page.o frame.o io.o power.o
CFLAGS=-nostdlib -ffreestanding -fno-stack-protector -std=gnu99 -Wall -m32
CC=gcc
#uncomment for MinGW GCC:
#CC=mingw32-gcc
ASFLAGS=-march=i686 --32
all: $(SOURCES)
	ld $(SOURCES) -T linker.ld -o bootImage.bin -melf_i386
clean:
	rm *.o -f
	rm bootImage.bin -f
	rm *~ -f
	rm a.out -f
install: all
	cp bootImage.bin /boot/project_gamma
