import serial
import time


# Commands for the target
# 0: Send Number of Lines
AllocateMemory = 0x31.to_bytes(1, "little")
AllocateRecord = 0x32.to_bytes(1, "little")
TransferData   = 0x3A.to_bytes(1, "little")
EraseChip      = 0x80.to_bytes(1, "little")
EraseApp0      = 0x40.to_bytes(1, "little")
EraseApp1      = 0x50.to_bytes(1, "little")
EraseApp2      = 0x60.to_bytes(1, "little")
EraseApp3      = 0x70.to_bytes(1, "little")
EraseApp4      = 0x90.to_bytes(1, "little")
FlashData      = 0xD0.to_bytes(1, "little")
ExcecuteApp    = 0xE0.to_bytes(1,"little") 
Exit           = 0x3E.to_bytes(1, "little")
ACK            = 0x10.to_bytes(1, "little")

CODESENT = 0
CODEFLASHED = 0

def sendmsg(msg):
    NACKs = 0
    # Clear the buffer
    ser.flush()
    ser.write(msg)
    # Wait for ACK
    while True:
        buff = ser.readall()
        if buff == b'ACK':
            break
        elif buff == b'NACK':
            ser.write(msg)
        else:
            # Delay 100 ms
            time.sleep(0.1)
            NACKs += 1
            print("NACKs: {}".format(NACKs))
            if NACKs > 1000:
                NACKs = 0
                ser.write(msg)



    
# Configure the serial port
ser = serial.Serial('COM6', 115200, timeout=0.01)
# Open the serial port
if not ser.isOpen():
    ser.open()
print(ser.is_open)

directory = input("Enter the directory of the hex file: ")

# Open the hex file
hexfile = open(directory, "r")
Lines = hexfile.readlines()

buff = ser.readall()
# Recieve Ready Signal
while buff != b'RDY':
    time.sleep(0.1)
    print("Waiting for Ready Signal")
    buff = ser.read_all()
ser.write(ACK)
print('Host is connected to the target')


while True:
    print('To download Code to the target, Enter 1\nTo Flash the Code, Enter 2\nTo Excecute the Code, Enter 3\nTo Erase the Code, Enter 4\nTo Erase the Chip, Enter 5\nTo Exit, Enter 6')
    cmnd = input("Enter Command: ")
    # Command 1: Send Number of Lines
    if cmnd == '1':
        address = Line[9:13]
        if address == '0800':
            print('The Bootloader resides at that address')
            break
        for i in range( (len(Lines) // 256) + 1):
            sendmsg(AllocateMemory)
            sendmsg(len(Lines).to_bytes(1, "little"))
        print('Memory Allocated Successfully')
        for count,Line in enumerate(Lines):
            
            # Allocate Record size
            sendmsg(AllocateRecord)
            sendmsg(bytes.fromhex(Line[1:3]))

            # Transfer Data
            sendmsg(TransferData)
            for i in range(0,len(Line[1:-1]),2):
                sendmsg(bytes.fromhex(Line[1+i:3+i]))
            print("Downloaded {} %".format(round(count/len(Lines)*100, 2)), end='\r')
        print('Data Transfered Successfully')

        CODESENT = 1
    # Command 3: Flash Data
    elif cmnd == '2':
        if CODESENT == 0:
            print('Code is not sent to the target')
            continue
        sendmsg(FlashData)
        print('Data Flashed Successfully')
        CODEFLASHED = 1
    
    # Command 4: Excecute App
    elif cmnd == '3':
        if CODEFLASHED == 0:
            print('Code is not sent to the target')
            continue
        sendmsg(ExcecuteApp)
        print('App is Excecuting')

    # Command 5: Exit
    elif cmnd == '4':
        for i in range(5):
            print('Erase Selected Sector : {}'.format(i))
            eraseID = input("Enter Erase ID: ")
            if eraseID == '0':
                sendmsg(EraseApp0)
            elif eraseID == '1':
                sendmsg(EraseApp1)
            elif eraseID == '2':
                sendmsg(EraseApp2)
            elif eraseID == '3':
                sendmsg(EraseApp3)
            elif eraseID == '4':
                sendmsg(EraseApp4)
            else:
                print('Invalid Erase ID')
        print('App is Erased Successfully')
    elif cmnd == '5':
        sendmsg(EraseChip)
        print('Chip is Erased Successfully')
    # Command 6: Exit
    elif cmnd == '7':
        break
    print(end='\r')
print('Host is disconnected from the target')
print('Exiting...')
print('Application is Exceucting')
