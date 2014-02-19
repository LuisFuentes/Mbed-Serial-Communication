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
        increase the LED's brightness or decrease it.
        Microcontroller shall return a response back to
        the host PC to inform the action executed.
        */

    pc.printf("Press '+' to turn LED1 brightness up, '-' to turn it down\n");
    while(1) {
        char c = pc.getc();
        if((c == '+') && (brightness < 0.5)) {
            brightness += 0.01;
            led = brightness;
            pc.putc('+');
        }
        if((c == '-') && (brightness > 0.0)) {
            brightness -= 0.01;
            led = brightness;
            pc.putc('-');
        } 
 
    }
}