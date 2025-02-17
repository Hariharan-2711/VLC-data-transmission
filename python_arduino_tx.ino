#define LIFI_LED 3
#define TIME 15

String data = "";

void setup()
{
  pinMode(LIFI_LED, OUTPUT);
  Serial.begin(9600);
  digitalWrite(LIFI_LED, HIGH);s
  //Serial.println("Arduino is connected");

}

void loop()
{
   if(Serial.available()>0)
  {
     data = Serial.readStringUntil('\n');
     int n = data.length();
     Serial.print(n);
     for(int i=0;i<n;i++){
      send_byte(data[i]);
      Serial.print(data[i]);
    }
    delay(1000);
  } 

  
}

void send_byte(char my_byte)
{
  digitalWrite(LIFI_LED, LOW);
  delay(TIME);

  //transmission of bits
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(LIFI_LED, (my_byte & (0x01 << i)) != 0 );
    delay(TIME);
  }

  digitalWrite(LIFI_LED, HIGH);
  delay(TIME);

}
