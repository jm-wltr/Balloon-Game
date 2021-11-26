int analogPin = A0;
int val = 0;  // variable to store the analog value read
int minsense = 300; //minimum analog value to trigger sensore in condition below
int lives = 6;


void setup() {
  Serial.begin(9600);
  for (int i = 1; i < 7; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
  }
 delay(1000);
}
  
void loop() {
  if (lives > 1) {
    val = analogRead(analogPin);
    Serial.println(val); //useful when calibrating sensor for minsense value
    delay(10);
    if (val < minsense){
      digitalWrite(lives, LOW);
      delay(1000);
      lives = lives-1;
    }
  }
}
