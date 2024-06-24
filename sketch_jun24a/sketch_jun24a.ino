char charInput = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    charInput = Serial.read();
  }
  if (charInput == 'Z') {
    digitalWrite(13, HIGH);
  }
  if (charInput == 'z') {
    digitalWrite(13, LOW);
  }
  if (charInput == 'F') {
    Go(255, 255);
  }
  if (charInput == 'B') {
    Go(-255, -255);
  }
  if (charInput == 'L') {
    Go(0, 255);
  }
  if (charInput == 'R') {
    Go(255, 0);
  }
  if (charInput == 'S') {
    Go(0, 0);
  }
}

  void Go(long SpeedL, long SpeedR) {
    if (SpeedL > 0){
      digitalWrite(2, HIGH);
      analogWrite(3, (255 - SpeedL));
    } else {
      digitalWrite(2, LOW);
      analogWrite(3, (0 - SpeedL));
    }
    if (SpeedR > 0){
      digitalWrite(4, HIGH);
      analogWrite(5, (255 - SpeedR));
    } else {
      digitalWrite(4, LOW);
      analogWrite(5, (0 - SpeedR));
    }
  }
