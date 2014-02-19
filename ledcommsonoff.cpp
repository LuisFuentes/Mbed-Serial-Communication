/***

Embed microcontroller serial port listener file
that shall listen to the host PC for bytes sent over.
Depending on the message, the LED on the microcontroller
will either light up or dim down. The microcontroller shall
response with what action was performed and send the message
back to the host PC.

***/ 

#include "mbed.h"
 
Serial pc(USBTX, USBRX); // tx, rx
PwmOut led(LED1);
 
float brightness = 0.0;
 
int main() {
        /* Listen for characters sent
        from host PC and checks whether to
        turn on or turn off the LED.
        Microcontroller shall return a response back to
        the host PC to inform the action executed.
        */
    // Set LED to off by default
    led =  0;
    pc.printf("Press '+' to turn LED1 on , '-' to turn LED1 off\n");
    while(1) {
        char c = pc.getc();
        if(c == '+')
        {
            // Check if led 1 is already on
            if (led == 1)
            {
                char ledon[] = "LED1 is already on\n";
                int len = strlen(ledon);
                int i;
                for (i=0; i<len; i++)
                {
                    pc.putc(ledon[i]);                
                }
            }
            else
            {
                led = 1;
                char ledon[] = "Turned on LED1\n";
                int len = strlen(ledon);
                int i;
                for (i=0; i<len; i++)
                {
                    pc.putc(ledon[i]);                
                }
            }
        }
        if(c == '-')
        {
            // Check if led 1 is already off
            if (led == 0)
            {
                char ledon[] = "LED1 is already off\n";
                int len = strlen(ledon);
                int i;
                for (i=0; i<len; i++)
                {
                    pc.putc(ledon[i]);                
                }
            }
            else
            {
                led = 0;
                char ledon[] = "Turned off LED1\n";
                int len = strlen(ledon);
                int i;
                for (i=0; i<len; i++)
                {
                    pc.putc(ledon[i]);                
                }
            } 
        }
    }
}