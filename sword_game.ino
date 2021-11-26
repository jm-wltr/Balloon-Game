int analogPin = A0;
int val = 0;  // variable to store the analog value read
int minsense = 300; //minimum analog value to trigger sensore in condition below


void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT); // Pin 13 is the default built-in LED on the arduino
}

void loop() {
  val = analogRead(analogPin);
  Serial.println(val); //useful when calibrating sensor for minsense value
  delay(10);
  if (val < minsense){
    digitalWrite(13, HIGH);
    delay(3000);
    digitalWrite(13, LOW);
  }
  
}
