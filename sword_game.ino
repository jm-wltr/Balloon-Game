int analogPin = A0;
int val = 0;  // variable to store the analog value read
int minsense = 50; //minimum analog value to trigger sensore in condition below
int lives = 4;
int pins[5] = {7, 10, 9, 4, 5};

void setup() {
  Serial.begin(9600);
  for (int i = -1; i < 7; i++) {
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], HIGH);
  }
 pinMode(3, OUTPUT);
 delay(10);
}

void loop() {
  if (lives > -1) {
    val = analogRead(analogPin);
    Serial.println(val); //useful when calibrating sensor for minsense value
    delay(10);
    if (val > minsense){
      digitalWrite(pins[lives], LOW);
      tone(3, 300);
      delay(100);
      noTone(3);
      delay(100);
      lives = lives-1;
    }
  }
  if (lives == -1){
   delay(5000);
   lives = 4;
   for (int i = -1; i < 7; i++) {
    digitalWrite(pins[i], HIGH);
    delay(10);
   }
  }
 }
