import  serial
import base64

serialcomm = serial.Serial('COM6',9600)


converted_string=serialcomm.read_until(b'\r').decode('utf-8') 
print(converted_string)
serialcomm.close()


decodeit = open('transmitted.png', 'wb')
decodeit.write(base64.b64decode(bytes(converted_string,'utf-8')))
decodeit.close()

