@ code
.text 
.global _start
_start:
	@ initial stack
	mov sp,#4096 

	@配置GPB5-8为输出模式
	ldr r0,=0x56000010 @GPBCON addr
	ldr r1,=0x400 @设置GPB5引脚为输出01
	str r1,[r0]


loop:
	@熄灭led1，把GPB5管脚电平推高，此时发光二极管led1是非导通状态；
	ldr r0,=0x56000014 @GPBDAT addr
	ldr r1,=0xffffffff @GPB5 set
	str r1,[r0]

	bl delay @跳转延时代码，手动延时，效率低

	@点亮led
	ldr r0,=0x56000014 @GPBDAT addr
	ldr r1,=0x0   		@GPB5 clear
	str r1,[r0]
	bl delay

	b loop

stop:
	b . @=>b stop

delay:
	ldr r3,=0xffff
wait:
	sub r3,r3,#1
	cmp r3,#0
	bne wait
	mov pc,lr
