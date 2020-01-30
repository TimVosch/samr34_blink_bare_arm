Bare AtSAML21J18B firmware
---
This code is a test for code on the AtSAML21J18B without any framework/bootloader/libraries. Although interesting this will probably not help you in your journey.

# What
This project contains all the code necessary to run C code on the AtSAML21J18B. This project contains startup code (Vector table, copying ROM to RAM, initializaing BSS, invoke main function) and a linker script for memory mapping.

The blink code resides in `main.c`.

# Why
I had issues getting any bootloader / core to run on the SAMR34 Penguino board (previously known as TinyLora board). I didn't want to use Atmel Studio because it is not available on Ubuntu.

I figured that i could write my own instructions (assembly) and flash it to the device, this **had** to work. Luckily it did, the next step was making life easier and running C.

# How

Jacob Mossberg his blog post: [run-c-program-bare-metal-on-arm-cortex-m3](https://jacobmossberg.se/posts/2018/08/11/run-c-program-bare-metal-on-arm-cortex-m3.html#c-program). Although several factors are different (such as the chip/cpu/programmer) the blog post can be followed perfectly fine with the datasheets for the AtSAML21J18B and the Cortex-M0+.

I'll spare you the time:  
 - [SAM L21 family datasheet](http://ww1.microchip.com/downloads/en/DeviceDoc/60001477A.pdf)
   - Relevant: Memory map, NVIC, PORT - I/O Pin Controller
 - [ARMv6-M Architecture Reference Manual](https://static.docs.arm.com/ddi0419/d/DDI0419D_armv6m_arm.pdf)
   - Contains a lot of implementation details. Since Cortex-M0+ supports ARMv6 CPU it is wise to look here. (specifically the VTOR and exceptions)