#include <SevSeg.h>
#include "IRremote.hpp"

#define IR_RECEIVE_PIN 11 // Signal Pin of IR receiver to Arduino Digital Pin 11

// 7seg pins
int pinA = 6;
int pinB = 5;
int pinC = 2;
int pinD = 3;
int pinE = 4;
int pinF = 7;
int pinG = 8;
int pinDP = 9;


void setup() {
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinDP, OUTPUT);

  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode"); 
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
} /*--(end setup )---*/


void loop() {
  // have we received an IR signal?
  if (IrReceiver.decode()) {
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); // Print "old" raw data
    IrReceiver.printIRResultShort(&Serial); // Print complete received data in one line
    IrReceiver.printIRSendUsage(&Serial);   // Print the statement required to send this data
    translateIR(); 
    IrReceiver.resume(); // receive the next value
  }  
} /* --(end main loop )-- */


// takes action based on IR code received
void translateIR() { 
  switch(IrReceiver.decodedIRData.decodedRawData) {

    case 0xB946FF00: Serial.println(" FORWARD"); forward();  break;
    case 0xBB44FF00: Serial.println(" LEFT");    left();     break;
    case 0xBF40FF00: Serial.println(" -OK-");    ok();       break;
    case 0xBC43FF00: Serial.println(" RIGHT");   right();    break;
    case 0xEA15FF00: Serial.println(" DOWN ");   down();     break;
    case 0xE916FF00: Serial.println(" 1");       one();      break;
    case 0xE619FF00: Serial.println(" 2");       two();      break;
    case 0xF20DFF00: Serial.println(" 3");       three();    break;
    case 0xF30CFF00: Serial.println(" 4");       four();     break;
    case 0xE718FF00: Serial.println(" 5");       five();     break;
    case 0xA15EFF00: Serial.println(" 6");       six();      break;
    case 0xF708FF00: Serial.println(" 7");       seven();    break;
    case 0xE31CFF00: Serial.println(" 8");       eight();    break;
    case 0xA55AFF00: Serial.println(" 9");       nine();     break;
    case 0xBD42FF00: Serial.println(" *");       star();     break;
    case 0xAD52FF00: Serial.println(" 0");       zero();     break;
    case 0xB54AFF00: Serial.println(" #");       pound();    break;
    case 0xFFFFFFFF: Serial.println(" REPEAT");              break;  
    default: Serial.println(" other button   ");
  
  }// End Case

  delay(500); // Do not get immediate repeat
} 

//functions representing numbers 0-9
void zero() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
}

void one() {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

void two() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
}

void three() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
}
  
void four() {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}
  
void five() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}
  
void six() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}
  
void seven() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}
  
void eight() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}
  
void nine() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

// functions representing other buttons
// including arrows, ok, *, and #
void star() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void pound() {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
}

void forward() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void right() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
}

void down() {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
}

void left() {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
}

void ok() {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}