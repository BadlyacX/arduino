const int trigPin = 8;
const int echoPin = 9;
double sonic_duration;
int left_1 = 2;
int left_2 = 3; // A
int right_1 = 4;
int right_2 = 5; // A

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
  fullSpeed();
  delay(1000);
  halfSpeed();
}


void fullSpeed() {
    // full speed
  digitalWrite(left_1, HIGH);
  digitalWrite(left_2, LOW);
  digitalWrite(right_1, HIGH);
  digitalWrite(right_2, LOW);
  delay(5000);
  digitalWrite(left_1, LOW);
  digitalWrite(left_2, LOW);
  digitalWrite(right_1, LOW);
  digitalWrite(right_2, LOW);
  delay(2000);
  digitalWrite(right_2, HIGH);
  digitalWrite(right_1, LOW);
  digitalWrite(left_2, HIGH);
  digitalWrite(left_1, LOW);
  delay(5000);
  digitalWrite(right_2, LOW);
  digitalWrite(right_1, LOW);
  digitalWrite(left_2, LOW);
  digitalWrite(left_1, LOW); 
}

void halfSpeed() {
   // half speed
  digitalWrite(left_1, HIGH);
  analogWrite(left_2, 255*0.5);
  digitalWrite(right_1, HIGH);
  analogWrite(right_2, 255*0.5);
  delay(5000);
  digitalWrite(left_1, LOW);
  digitalWrite(left_2, LOW);
  digitalWrite(right_1, LOW);
  digitalWrite(right_2, LOW);
  delay(2000);
  analogWrite(right_2, 255*0.5);
  digitalWrite(right_1, LOW);
  analogWrite(left_2, 255*0.5);
  digitalWrite(left_1, LOW);
  delay(5000);
  digitalWrite(right_2, LOW);
  digitalWrite(right_1, LOW);
  digitalWrite(left_2, LOW);
  digitalWrite(left_1, LOW); 
}
