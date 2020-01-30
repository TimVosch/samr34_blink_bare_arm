all: build/main.hex

build/startup.o: startup.c
	arm-none-eabi-gcc -c -mthumb -mcpu=cortex-m0plus -O0 -g -o build/startup.o startup.c

build/main.o: main.c
	arm-none-eabi-gcc -c -mthumb -mcpu=cortex-m0plus -O0 -g -o build/main.o main.c

build/main.elf: build/startup.o build/main.o
	arm-none-eabi-ld -Tsaml21.ld -o build/main.elf build/startup.o build/main.o

build/main.hex: build/main.elf
	arm-none-eabi-objcopy -O ihex build/main.elf build/main.hex
	arm-none-eabi-size build/main.elf

clean:
	rm -f build/main.o build/startup.o build/main.elf build/main.hex
