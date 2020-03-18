#ReadSerial.py
import serial
import time

port = "/dev/ttyUSB0"

logfile = "Accel_log.txt"
write_mode = "w" #overwrite existing

def readLine(port):
    return port.read()

def bytes_to_int(input_bytes):
    result = 0
    for b in input_bytes:
        result = result * 256 + int(b)

    return result

file = open(logfile,write_mode)
ser = serial.Serial(port, baudrate = 14400 )
print ("starting")
while True:
    #print ("sending synch")
    #ser.write("A")
    rcv = readLine(ser)
    print ("received:",rcv)
    #print ("Int = ", bytes_to_int(rcv))
    file.write(str(bytes_to_int(rcv)))
    file.write("; ")