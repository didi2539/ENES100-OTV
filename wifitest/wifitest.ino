#include <Enes100.h>

const int TX = 9;
const int RX = 10;
char coordinates[100];

void setup() {
//Connect digital pin 8 to the Tx pin of the wifi module.
//Connect digital pin 9 to the Rx pin of the wifi module.
Serial.begin(115200);
Serial.println("Beginning Connection type shi");
Enes100.begin("Smokey", FIRE, 566, 1120, TX, RX);
Serial.println(Enes100.isConnected() ? "connected" : "not connected");
Enes100.println("Hello World, Team Smokey is connected!");

Serial.println(Enes100.isVisible() ? "OTV is visible" : "OTV is not visible");
// Some other setup code...
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(Enes100.isVisible() ? "OTV is visible" : "OTV is not visible");
  sprintf(coordinates, "Position: (%f, %f)", Enes100.getX(), Enes100.getY());
  Serial.print("Coordinates: (");
  Serial.print(Enes100.getX());
  Serial.print(", ");
  Serial.print(Enes100.getY());
  Serial.println(")");
  delay(1500);
}
