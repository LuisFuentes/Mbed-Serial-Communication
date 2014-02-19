/***

Embed microcontroller serial port listener file
that shall listen to the host PC and print out
strings sent from the host PC.

***/
#include "mbed.h"              
 
Serial pc(USBTX, USBRX);
 
int main() {
    while(1) {
        /* Listen for characters sent
        from host PC and return the chracters
        through the serial port via USB back
        to the host.
        */
        pc.putc(pc.getc());
    }
}