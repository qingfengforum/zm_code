CC := arm-linux-gcc
LD := arm-linux-ld
OBJCOPY := arm-linux-objcopy

#``可以把shell命令的结果当做字符串传递给makefile的变量
#| shell命令管道.
# 该命令使得BIN = 当前所在目录的名称。
#tip head.s 要先与*.c文件，因为地址0x0要为head.s中的代码
BIN := `pwd|xargs basename`
S_SRC	:=	$(wildcard *.s)
OBJS	:= 	$(S_SRC:%.s=%.o)
C_SRC	:= 	$(wildcard *.c)
OBJS	+=	$(C_SRC:%.c=%.o)

$(BIN):$(OBJS)
	$(LD) -Ttext 0x0 $(OBJS) -o $(BIN).elf
	$(OBJCOPY) -S $(BIN).elf -O binary $(BIN).bin


%.o:%.c
	$(CC) -o $@ -c $<
#arm-linux-gcc -c -o main.o main.c
#此处发生循环执行命令，make将对所有的c文件进行逐一的编译

%.o:%.s
	$(CC) -o $@ -c $<

.PHONY: clean
clean:
	rm -rf *.o *.elf *.bin

		
