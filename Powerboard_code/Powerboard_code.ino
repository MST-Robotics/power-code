#include <Wire.h>


#define SHUTOFF_PIN 12
#define SHUTOFF 0xEE

void setup() {
  // i2c setup
  pinMode(SHUTOFF_PIN, OUTPUT);

  int receiveEvent = 0;
  

  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(115200);           // start serial for output

}

void loop() {
  //recieve i2c packet
  //set shutoff_pin if packet is shutoff

  int x = Wire.read();    // receive byte as an integer
  Serial.println(x);         // print the integer
  
  if (x == SHUTOFF) {
    digitalWrite(SHUTOFF_PIN, LOW);
  }
}
