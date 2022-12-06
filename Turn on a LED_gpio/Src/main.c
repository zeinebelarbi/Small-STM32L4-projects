

#include <stdint.h>

//AHBE2ENR 0x 4002 104c

int main(void)
{// 1-  Enable the clock pour GPIOB
	uint32_t *pClkReg =(uint32_t*)0x4002104c;
	*pClkReg |= (1<<1);
	//2-  Configure  pin PB14 as OUTPUT
	uint32_t *PMODERReg =(uint32_t*)0x48000400;
	*PMODERReg |=(1<<28),
	*PMODERReg &=~(1<<29);
	//3- Turn on the LED
	uint32_t *pOdrReg =(uint32_t*)0x48000414;
	*pOdrReg |=(1<<14);
for(;;);
}
