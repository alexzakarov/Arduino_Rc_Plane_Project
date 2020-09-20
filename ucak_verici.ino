#include <SPI.h> 
#include <nRF24L01.h>
#include <RF24.h>


#define CE_PIN   7
#define CSN_PIN 8

#define x_axis A0 // x axis
#define y_axis A1 //y axis
#define z_axis A2



const uint64_t pipe = 0xE8E8F0F0E1LL; 
RF24 radio(CE_PIN, CSN_PIN); 

int data[3];  

void setup() 
{

  radio.begin();
  radio.openWritingPipe(pipe);

}

void loop()   
{

  data[0] = analogRead(x_axis);
  data[1] = analogRead(y_axis);
  data[2] = analogRead(z_axis);
  radio.write( data, sizeof(data) ); 

  
}
