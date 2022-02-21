int analogPin = A0; //analog input pin for piezoelectric sensor
int buzzerPin = 3;
int pins[5] = {12, 10, 9, 6, 4}; //LED pins
int val = 0;  // variable to store the analog value read
int minsense = 50; //minimum analog value to trigger sensor
int lives = 5; //initial lives
int chord[5] = {196, 294, 392, 494, 784}//frequencies for sound at the end

//turn on all LEDs
void setup(){
  Serial.begin(9600);
  for(int i = 0; i < 5; i++){
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], HIGH);
  }
  pinMode(buzzerPin, OUTPUT);
  delay(10);
}

//main loop
void loop(){
  //detect hits and turn off lights
  if(lives > 0){
    val = analogRead(analogPin);
    Serial.println(val); //useful when calibrating for minsense value
    delay(10);
    if (val > minsense){
      digitalWrite(pins[lives-1], LOW);
      tone(buzzerPin, 300);
      delay(100);
      noTone(buzzerPin);
      delay(100);
      lives = lives-1;
    }
  }
  //game reset and chord jingle
  if (lives == 0){
    lives = 5;
    for(int i = 0; i < 5; i++){
      pinMode(pins[i], OUTPUT);
      digitalWrite(pins[i], HIGH);
      tone(buzzerPin, chord[i]);
      delay(100);
      digitalWrite(pins[i-1], LOW);
      noTone(buzzerPin);
    }
    delay(200);
    tone(buzzerPin, 988);
    for(int i = 0; i < 5; i++){
      digitalWrite(pins[i], HIGH);
    }
    delay(1500);
    for(int i = 0; i < 5; i++){
      digitalWrite(pins[i], LOW);
    }
    noTone(buzzerPin);
    delay(2800);
  }
}
