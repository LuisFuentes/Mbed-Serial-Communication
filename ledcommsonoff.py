'''
Communicates with Mbed LPC1768
microcontroller via usb serialport.
Indefinitely waits for user input to
send through serial port and reads from
the port the response from the microcontroller.
Based on the user's input sent to the
microcontroller, LED 1 will either light up
or turn off.
'''
import time
import serial
# Establish connection to the Mbed unit.
ser = serial.Serial('/dev/ttyACM0',
        9600, timeout=2)
def ledcomms():
    # Print instructions from Microcontroller
    print ser.readline()
    while True:
        serial_input = raw_input("Enter '+' or '-':\n")
        ser.write(serial_input + "\n")
        print "Sent string: %s" % serial_input
        time.sleep(1)
        print "Response: %s" % ser.readline()

if __name__ == "__main__":
    ledcomms()
