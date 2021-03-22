#include <SoftwareSerial.h>

SoftwareSerial slave(6, 7); // RX | TX
const int button1 = 2;
const int button2 = 9;
const int button3 = 8;
const int button4 = 1;
const int button5 = 0;
const int button6 = 5;
const int button7 = 4;
const int button8 = 3;
const int button9 = 13;
const int button10 = 12;
const int button11 = 11;
const int button12 = 10;
const int button13 = 6;

float lamatekan = 12;


int buttonState1 = 0; 
int buttonLastState1 = 0;
int buttonState2 = 0; 
int buttonLastState2 = 0;
int buttonState3 = 0; 
int buttonLastState3 = 0;
int buttonState4 = 0; 
int buttonLastState4 = 0;
int buttonState5 = 0; 
int buttonLastState5 = 0;
int buttonState6 = 0; 
int buttonLastState6 = 0;
int buttonState7 = 0; 
int buttonLastState7 = 0;
int buttonState8 = 0;
int buttonLastState8 = 0;
int buttonState9 = 0;
int buttonLastState9 = 0;
int buttonState10 = 0;
int buttonLastState10 = 0;
int buttonState11 = 0;
int buttonLastState11 = 0;
int buttonState13 = 0;
int buttonLastState13 = 0;



int analog1x = 0;
int analog2x = 0;
int analog1y = 0;
int analog2y = 0;


void setup()
{
   // HC-05 default speed in AT command more for bluetooth configuration
  Serial.begin(9600);
  slave.begin(9600);                                  // HC-05 default speed in AT command more
  
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
  pinMode(button6, INPUT);
  pinMode(button7, INPUT);
  pinMode(button8, INPUT);
  pinMode(button9, INPUT_PULLUP);
  pinMode(button10, INPUT_PULLUP);
    pinMode(button11, INPUT);
    pinMode(button13, INPUT);

  
}

void loop()
{
  buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);
  buttonState3 = digitalRead(button3);
  buttonState4 = analogRead(A6);
  buttonState5 = analogRead(A7);
  buttonState6 = digitalRead(button6);
  buttonState7 = digitalRead(button7);
  buttonState8 = digitalRead(button8);
  buttonState9 = analogRead(A2);
  buttonState10 = digitalRead(button10);
  buttonState11 = digitalRead(button11);
  buttonState13 = digitalRead(button13);



   analog1x = analogRead(A0);
   analog2x = analogRead(A1);
   analog1y = analogRead(A3);
   analog2y = analogRead(A4);
 
  Serial.print(analog1x);
  Serial.print(" ");
  Serial.print(analog2x);
  Serial.print(" ");
  Serial.print(buttonState10);
  Serial.print("   ");
  Serial.print(analog1y);
  Serial.print(" ");
  Serial.println(analog2y);
  Serial.print(" ");
   Serial.print(buttonState9);
  Serial.print("    ");
  Serial.print(lamatekan);
  Serial.print("  ");
 
  //kondisi buat button si relay 
  //for Relay Condition mode
      if (buttonState11 == 1)
      {
          if (buttonState10 == 1)
          {
            delay(1); 
            lamatekan=0;
          }
          else if(buttonState10 == 0 )
          {
            lamatekan=0;
            while(buttonState10 == 0)
          { 
            buttonState10 = digitalRead(button10);
            delay(1); 
            lamatekan=lamatekan+100;
          }
      }
  
        
      //oke guys so in below these code if user press long or press fast it has 2 different condition because limited amount number button
     
      //Mode 1
      if (buttonState1 == 1) 
      {
        Serial.write('1');
        slave.write('1');
        buttonLastState1 = buttonState1;
      }   
      else if(buttonState2 == 1)
      {
        Serial.write('2');
        slave.write('2');
        buttonLastState2 = buttonState2;
      }
      else if(buttonState6 == 1)
      {
        Serial.write('L');
        slave.write('L');
        buttonLastState6 = buttonState6;
      }
      else if (buttonState3 == 1) 
      {
        Serial.write('3');
        slave.write('3');
        buttonLastState3 = buttonState3;
      }
     
      else if (buttonState4 > 100) 
      {
        Serial.write('4');
        slave.write('4');
        buttonLastState4 = buttonState4;
      }
      else if (buttonState5 > 100) 
      {
        Serial.write('5');
        slave.write('5');
        buttonLastState5 = buttonState5;
      }
      else if (buttonState6 == 1) 
      {
        Serial.write('6');
        slave.write('6');
        buttonLastState6 = buttonState6;
      }
      else if (buttonState7 == 1) 
      {
        Serial.write('7');
        slave.write('7');
        buttonLastState7 = buttonState7;
      }
      else if(buttonState2 == 1)
      {
        Serial.write('2');
        slave.write('2');
        buttonLastState2 = buttonState2;
      }
      else if (buttonState8 == 1) 
      {
        Serial.write('8');
        slave.write('8');
        buttonLastState8 = buttonState8;
      }
      else if (buttonState9 < 100) 
      {
        Serial.write('9');
        slave.write('9');
        buttonLastState9 = buttonState9;
      }
      else if (analog1x > 700) 
      {
        Serial.write('b');
        slave.write('b');
        buttonLastState10 = buttonState10;
      }
      else if (analog1x < 350) 
      {
        Serial.write('c');
        slave.write('c');
        buttonLastState10 = buttonState10;
      }
      else if (analog2x > 700) 
      {
        Serial.write('d');
        slave.write('d');
        buttonLastState10 = buttonState10;
      }
      else if (analog2x < 350) 
      {
        Serial.write('e');
        slave.write('e');
        buttonLastState10 = buttonState10;
      }
      else if (analog1y > 700) 
      {
        Serial.write('f');
        slave.write('f');
        buttonLastState10 = buttonState10;
      }
      else if (analog1y < 350) 
      {
        Serial.write('g');
        slave.write('g');
        buttonLastState10 = buttonState10;
      }
      else if (analog2y > 700) 
      {
        Serial.write('h');
        slave.write('h');
        buttonLastState10 = buttonState10;
      }
      else if (analog2y < 350) 
      {
        Serial.write('i');
        slave.write('i');
        buttonLastState10 = buttonState10;
      }
      else
      {
        slave.write('?');
      }


      //relay hidup mati
      if(lamatekan > 0)
      {
        Serial.write('a');
        slave.write('a');
      }
      if(lamatekan >= 500)
      {
        Serial.write('z');
        slave.write('z');
      }
      }
       if (buttonState10 == 1)
      {
        delay(100); 
        lamatekan=0;
      }
      else if(buttonState10 == 0 )
      {
        lamatekan=0;
        while(buttonState10 == 0)
      { 
        buttonState10 = digitalRead(button10);
        delay(100); 
        lamatekan=lamatekan+100;
      }
      }
  
        
      
      //Mode 2
      if (buttonState11 == 0)
      {
      if (buttonState1 == 1) 
      {
        Serial.write('1');
        slave.write('1');
        buttonLastState1 = buttonState1;
      }   
      else if(buttonState2 == 1)
      {
        Serial.write('2');
        slave.write('2');
        buttonLastState2 = buttonState2;
      }
      else if (buttonState3 == 1) 
      {
        Serial.write('3');
        slave.write('3');
        buttonLastState3 = buttonState3;
      }
      else if (buttonState4 > 100) 
      {
        Serial.write('4');
        slave.write('4');
        buttonLastState4 = buttonState4;
      }
      else if (buttonState5 > 100) 
      {
        Serial.write('5');
        slave.write('5');
        buttonLastState5 = buttonState5;
      }
      else if (buttonState6 == 1) 
      {
        Serial.write('6');
        slave.write('6');
        buttonLastState6 = buttonState6;
      }
      else if (buttonState7 == 1) 
      {
        Serial.write('7');
        slave.write('7');
        buttonLastState7 = buttonState7;
      }
      else if(buttonState2 == 1)
      {
        Serial.write('2');
        slave.write('2');
        buttonLastState2 = buttonState2;
      }
      else if (buttonState8 == 1) 
      {
        Serial.write('8');
        slave.write('8');
        buttonLastState8 = buttonState8;
      }
      else if (buttonState9 < 100) 
      {
        Serial.write('9');
        slave.write('9');
        buttonLastState9 = buttonState9;
      }
      else if (analog1x > 700) 
      {
        Serial.write('k');
        slave.write('k');
        buttonLastState10 = buttonState10;
      }
      else if (analog1x < 350) 
      {
        Serial.write('l');
        slave.write('l');
        buttonLastState10 = buttonState10;
      }
      else if (analog2x > 700) 
      {
        Serial.write('p');
        slave.write('p');
        buttonLastState10 = buttonState10;
      }
      else if (analog2x < 350) 
      {
        Serial.write('x');
        slave.write('x');
        buttonLastState10 = buttonState10;
      }
      else if (analog1y > 700) 
      {
        Serial.write('w');
        slave.write('w');
        buttonLastState10 = buttonState10;
      }
      else if (analog1y < 350) 
      {
        Serial.write('v');
        slave.write('v');
        buttonLastState10 = buttonState10;
      }
      else if (analog2y > 700) 
      {
        Serial.write('H');
        slave.write('H');
        buttonLastState10 = buttonState10;
      }
      else if (analog2y < 350) 
      {
        Serial.write('I');
        slave.write('I');
        buttonLastState10 = buttonState10;
      }
      else
      {
        slave.write('?');
      }


      //relay hidup mati
      if(lamatekan > 0)
      {
        Serial.write('a');
        slave.write('a');
      }
      if(lamatekan >= 500)
      {
        Serial.write('z');
        slave.write('z');
      }
      }}
