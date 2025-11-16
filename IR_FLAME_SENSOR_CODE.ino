// IR Flame Sensor Module
//pin definitions
int flame0= A0; 
int flame1= A1; 
int flame2= A2; 
int flame3= A3;
boolean flameList[]= {false, false, false, false};
 

void setup() {
  Serial.begin(19200); // Start the serial communication
}

void loop() {
  int flaVal0 = analogRead(flame0); // Read the flame sensor module value
  int flaVal1 = analogRead(flame1); 
  int flaVal2 = analogRead(flame2); 
  int flaVal3 = analogRead(flame3); 
  delay(200);
  
  int threshold = 35;
  if (flaVal0<threshold){ 
    Serial.println("Flame0!!");
    flameList[0] = true;    
  }else{
    Serial.println("No Flame0");
  }
  
  if (flaVal1<threshold){ 
    Serial.println("Flame1!!");
    flameList[1] = true;
  }else{
    Serial.println("No Flame1");
  }
  
  if (flaVal2<threshold){
    Serial.println("Flame2!!");
    flameList[2] = true;
  }else{
    Serial.println("No Flame2");
  }
  
  if (flaVal3<threshold){
    Serial.println("Flame3!!");
    flameList[3] = true;
  }else{
    Serial.println("No Flame3");
  }

  int count = 0;

  for(int i = 0; i < 4; i++){
    if (flameList[i]){
      count++;
    }
  }

  Serial.println(count);
}
