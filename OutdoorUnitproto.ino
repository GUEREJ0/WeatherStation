// This code was given to test out the 4 digit display
// I would have to work on it accordingly to make sure it can actually display all numbers


//www.elegoo.com
//2016.12.12

int latch=9;  //74HC595  pin 9 STCP
int clock=10; //74HC595  pin 10 SHCP
int data=8;   //74HC595  pin 8 DS
int temperaturePin = 3;
int LED;
int tempReading;
int connectionPin0 = 1;
int connectionPin1 = 2;
int connectionPin2 = 3;
int connectionPin3 = 4;
int connectionPin4 = 5;
bool connected = false;


unsigned char table[]=
{0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c
,0x39,0x5e,0x79,0x71,0x00};//Display digital data

void setup() {
  pinMode(latch,OUTPUT);
  pinMode(clock,OUTPUT);
  pinMode(data,OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(temperaturePin, INPUT);
  pinmode(connectionPin0, OUTPUT);
  pinMode(connectionPin1, OUTPUT);
  pinMode(connectionPin2, OUTPUT);
  pinMode(connectionPin3, OUTPUT);
  pinMode(connectionPin4, OUTPUT);

}
/*   The most common method of using 74CH595
 *   latch->LOW : Begin transmitting signals.
 *   shiftOut(dataPin, clockPin, bitOrder, value)
 *   dataPin: the pin on which to output each bit. Allowed data types: int.
 *   clockPin: the pin to toggle once the dataPin has been set to the correct value. Allowed data types: int.
 *   bitOrder: which order to shift out the bits; either MSBFIRST or LSBFIRST. (Most Significant Bit First, or, Least Significant Bit First).
 *   value: the data to shift out. Allowed data types: byte. 
 *   latch->HIch : The end of the transmission signal.
*/
void Display(unsigned char num)
{

  digitalWrite(latch,LOW);
  shiftOut(data,clock,MSBFIRST,table[num]);
  digitalWrite(latch,HIGH);
  
}
void loop() {
  tempReading = Serial.read(temperaturePin)
  Display(TemperaturePin);
  if(connected){
    digitalWrite(LED, HIGH);
  }
}