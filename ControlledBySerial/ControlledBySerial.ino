const int trigPin = 8;
const int echoPin = 9;
int left_1 = 2;
int left_2 = 3; // Analog
int right_1 = 4;
int right_2 = 5; // Analog

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(left_1, OUTPUT);
  pinMode(left_2, OUTPUT);
  pinMode(right_1, OUTPUT);
  pinMode(right_2, OUTPUT);
}
void loop() {
  if (Serial.available() > 0) {
    char cmd = Serial.read();
    if (cmd == 'f') {
      Go(0, 0);
      delaySecs(1);
      Go(255, 255);
    } else if (cmd == 'b') {
      Go(0, 0);
      delaySecs(1);
      Go(-255,-255);
    } else if (cmd == 's') {
      Go(0, 0);
    }
  }
}


void Go(int speedR, int speedL) {
  if (speedR > 0) {
    digitalWrite(right_1, HIGH);
    analogWrite(right_2, 255 - speedR);
  } else if (speedR < 0) {
     digitalWrite(right_1, LOW);
     analogWrite(right_2, speedR*-1);
  } else if (speedR == 0) {
     digitalWrite(right_1, LOW);
     digitalWrite(right_2, LOW);    
  }
  if (speedL > 0) {
    digitalWrite(left_1, HIGH);
    analogWrite(left_2, 255 - speedL);
  } else if (speedL < 0) {
    digitalWrite(left_1, LOW);
    analogWrite(left_2, speedL*-1);
  } else if (speedL == 0) {
    digitalWrite(left_1, LOW);
    analogWrite(left_2, LOW);
  }
}

void delaySecs(int secs) {
  delay(1000 * secs);
}
