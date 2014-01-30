        ####       ##       ##    ##       ##    ##       ##
       ## ##      ###      ###   ###      ###   ###      ###
      ##  ##     ####     ####  ####     ####  ####     ####
     ##         ## ##    ## ## ## ##    ## ## ## ##    ## ##
    ##   ###   ######   ##  ####  ##   ##  ####  ##   ######
   ##     ##  ##   ##  ##   ###   ##  ##   ###   ##  ##   ##
  ########## ##    ## ##    ##    ## ##    ##    ## ##    ##
  
  NOTE: The timestamps for many of the files sometimes are in 1998. This is my
        fault - my CMOS battery is dead, and I forget to set the clock!
  Overview:
  Execution begins in boot.s, and goes to kernel_main(), in kernel_main.c.
  After that, execution is interrupt-driven, so looking at the kernel_main
  function will be pointless: it's an infinite loop. The purpose of the kernel
  is to get the computer in a usable state, and then respond to interrupts, 
  from software and hardware, e.g.: keyboards.
  
  Compiling on Winblows:
  [UNTESTED]
  You will need the MinGW GCC port as well as the make utility.
  Edit the Makefile so that the 
  CC=gcc
  line reads
  CC=mingw32-gcc
  This will change to the MinGW GCC compiler.
 Change directory (at a command prompt) to the source directory.
 Run 'mingw32-make'
 This will generate a Multiboot-compatible boot image, called bootImage.bin
 
 Running:
 You will need the GRUB bootloader installed
 At the GRUB boot menu, hit 'c'
 Type: "multiboot (hd0, msdosX)/path_to_source_dir/bootImage.bin", where X is the number of your Windows partition.
 This will load the kernel
 Then type "boot", and the kernel will load and run
