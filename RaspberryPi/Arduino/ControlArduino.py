# ls /dev/tty*
import serial
import sys
import time

print(sys.argv[1])

#ser = serial.Serial('/dev/ttyACM1', 115200)
ser = serial.Serial()
ser.port='/dev/ttyACM1'
ser.baudrate=115200

ser.open();
ser.write(str(sys.argv[1] + '\n'))
ser.close();


