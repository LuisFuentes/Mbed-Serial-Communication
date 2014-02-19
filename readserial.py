'''
Communicates with Mbed LPC1768
microcontroller via usb serialport.
Indefinitely waits for user input to
send through serial port and reads from
the port the response from the microcontroller.
'''
import serial
# Establish connection to the Mbed unit.
ser = serial.Serial('/dev/ttyACM0',
        9600, timeout=2)


while True:
    serial_input = raw_input(
            "Enter string to send to microcontroller: ")
    ser.write(serial_input + "\n")
    print "Sent string: %s" % serial_input
    print "Response: %s" % ser.readline()
