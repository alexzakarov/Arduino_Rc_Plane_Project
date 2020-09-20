#include <SPI.h>
#include <nRF24L01.h> 
#include <RF24.h>
#include <Servo.h>

#define CE_PIN   7
#define CSN_PIN 8

int x_hiz=0;
int y_hiz=0;
int z_hiz=0;

Servo esc;
Servo servo;
Servo servo1;


const uint64_t pipe = 0xE8E8F0F0E1LL;

RF24 radio(CE_PIN, CSN_PIN); 

int data[3]; 

void setup()   
{
esc.attach(5);
servo.attach(2);
servo1.attach(3);
    
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();;
}


void loop() {
  if ( radio.available() )
  {
    radio.read( data, sizeof(data) ); 
    


hareket(data[0],data[1],data[2]);

  }
}

void hareket(int x_axis, int y_axis, int z_axis ) {
 
 x_hiz= map(x_axis,0,1023,0,180);
esc.write(x_hiz);
 
 y_hiz= map(y_axis,0,1023,0,90);
servo.write(y_hiz);

z_hiz= map(z_axis,0,1023,0,75);
servo1.write(z_hiz);


  }

