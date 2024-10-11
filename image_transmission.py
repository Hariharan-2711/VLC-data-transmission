import base64
import serial
import time


image2string = open("16p_facebook.png", "rb")
string = base64.b64encode(image2string.read())
# print(len(string))
# print(type(string))


serialcomm = serial.Serial('/dev/ttyACM0',9600)
serialcomm.timeout = 1

converted_string = string.decode("utf-8") 
converted_string+='\r'
print(converted_string)
# print(len(converted_string))
# print(type(converted_string))
while True:
    s = input("1->transmit,0->exit ").strip()
    if s == '0':
        print("Exit")
        break
    serialcomm.write(converted_string.encode())
    time.sleep(0.5)
    
out = serialcomm.read_until(b'\r').decode('utf-8')
res = bytes(out, 'utf-8')
serialcomm.close()



# decodeit = open('transmitted.png', 'wb')
# decodeit.write(base64.b64decode(string))
# decodeit.close()
