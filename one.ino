#include<Servo.h>

Servo myServo;

void setup() {
  Serial.begin(9600);
  myServo.attach(9);
}

char rx_byte;

void loop() {
  if(Serial.available() > 0){
    rx_byte = Serial.read();
    if(rx_byte == '0'){
      Serial.println("Cw");
      myServo.write(0);
    }
    else if(rx_byte == '1'){
      Serial.println("Stop");
      myServo.write(90);
    }    
    else if(rx_byte == '2'){
      Serial.println("Ccw");
      myServo.write(180);
    }    
  }
}
