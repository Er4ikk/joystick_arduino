
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

int controller[2][2];//0--c_mid[l/r][x/y]-->1023
int c_mid[2][2]={{490,490},{490,490}};
const bool _left=0;
const bool _right=1;
const bool _x=0;
const bool _y=1;

int joystick_right_x=A0;
int joystick_right_y=A1;

int joystick_left_x=A2;
int joystick_left_y=A3;

RF24 radio(8, 10); // CE, CSN
const byte address[6] = "00001"; //same address must BE ON THE RECEIVER


void setup(){
  Serial.begin(9600);
  radio.begin();                  //Starting the Wireless communication
  radio.openWritingPipe(address); //Setting the address where we will send the data
  radio.setPALevel(RF24_PA_MIN);  //You can set it as minimum or maximum depending on the distance between the transmitter and receiver.
  radio.stopListening();    //Setting this arduino as a trasmitter
}

void loop(){
  controller[_right][_x]=analogRead(joystick_right_x);
  controller[_right][_y]=analogRead(joystick_right_y);
  controller[_left][_x]=analogRead(joystick_left_x);
  controller[_left][_y]=analogRead(joystick_left_y);
  
  Serial.println("right x value ");
  Serial.print(controller[_right][_x]);
  
    Serial.println("right y value ");
  Serial.print(controller[_right][_y]);
   
    Serial.println("left x value ");
  Serial.print(controller[_left][_x]);
  
   
    Serial.println("left y value ");
  Serial.print(controller[_left][_x]);
    
  radio.write(&controller,4*sizeof(int));
}
