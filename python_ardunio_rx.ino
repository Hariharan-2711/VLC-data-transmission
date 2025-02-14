#define LED_PIN 3
#define LDR_LIFI 2
#define TIME 15

bool previous_state;
bool current_state;

void setup() 
{
    Serial.begin(9600);
    pinMode(LED_PIN, OUTPUT);
}

void loop() 
{
  current_state = get_ldr();
  if(!current_state && previous_state)
  {
    print_byte(get_byte());
  }
  previous_state = current_state;
}

bool get_ldr()
{
  int voltage = digitalRead(LDR_LIFI);
  return voltage ? false:true;
}

char get_byte()
{
  char ret = 0;
  delay(TIME*1.5);
  for(int i = 0; i < 8; i++)
  {
   ret = ret | get_ldr() << i; 
   delay(TIME);
  }
  return ret;
}
void print_byte(char my_byte)
{
  
  Serial.print(my_byte);
}
