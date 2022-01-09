
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
int value_right_x=0;
int value_right_y=0;

int joystick_left_x=A2;
int joystick_left_y=A3;
int value_left_x=0;
int value_left_y=0;



RF24 radio(8, 10); // CE, CSN
const byte address[6] = "00001"; //same address must BE ON THE RECEIVER


void setup(){}

void loop(){}
