#include <wiringPi.h>
#include <stdio.h>
#include "devices.hpp"

int main(void)
{
	if(wiringPiSetup() == -1){ //when initialize wiringPi failed, print message to screen
		printf("setup wiringPi failed !\n");
		return -1; 
	}
	
	Led led(7);
    Button button(0);

	while(1){
        if (button.isPressed()){
		    led.toggle();   //led on
            delay(250);
        } 
	}

	return 0;
}

