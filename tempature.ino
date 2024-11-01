float celsiusdegrees = 0;

void setup() {
  //setup pin
  pinMode(2, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
  
}
//convert to celsius degrees
void convert(){
  int readOut = analogRead(A0);
  float voltage = readOut * (5.0 / 1023.0);
   celsiusdegrees = voltage * 100.0;
}

void loop() {
  //call the convert function
  convert();
  //main portion
  int readOut = analogRead(A0);
  
  if (celsiusdegrees > 25.0) { // Adjust threshold as needed
    digitalWrite(2, LOW);
    digitalWrite(6, HIGH);
  } else {
    digitalWrite(2, HIGH);
    digitalWrite(6, LOW);
  }
  Serial.println("celsius:");
  Serial.println(celsiusdegrees);
  delay(1000);
 
}
