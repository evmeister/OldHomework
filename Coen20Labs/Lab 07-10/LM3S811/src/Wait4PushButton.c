#include <stdint.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/gpio.h"
#include "inc/sysctl.h"
#include "inc/systick.h"

#define PUSH_BUTTON GPIO_PIN_4

static uint8_t pb_samples = 0 ;

void SysTickHandler(void)
	{
	pb_samples <<= 1 ;
	if (GPIOPinRead(GPIO_PORTC_BASE, PUSH_BUTTON) == 0) pb_samples |= 0x01 ;
	}

static void Initialize(void)
	{
	static int initialized = 0 ;
	
	if (!initialized)
		{
		int onemsec = SysCtlClockGet() / 1000 ;
		SysTickPeriodSet(onemsec) ;	// SysTick interrupts occur every millisecond
		SysTickEnable() ;		// start the SysTick counter
		SysTickIntEnable() ;		// enable SysTick counter to interrupt

		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC) ;		// enable push button
		GPIOPinTypeGPIOInput(GPIO_PORTC_BASE, PUSH_BUTTON) ;	// as an input pin
		initialized = 1 ;
		}
	}

void Wait4PushButton(void)
	{
	Initialize() ;
	while (pb_samples != 0x00) /* wait for PB release */ ;
	while (pb_samples != 0xFF) /* wait for PB pushed  */ ;
	}

