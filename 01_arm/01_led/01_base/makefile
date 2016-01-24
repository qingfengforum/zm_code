head:head.s
	arm-linux-gcc -o head.o -c head.s
	arm-linux-ld -o head.elf -Ttext 0x0 head.o 
	arm-linux-objcopy -O binary -S head.elf head.bin

.PHONY: clean head
clean:
	rm -rf *.o *.elf *.bin
