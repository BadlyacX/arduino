const int trigPin = 8;
const int echoPin = 9;
double sonic_duration;
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

}

void rightForward(int p) {
  double s = 255*(1 - (0.01*p));
  digitalWrite(right_1, HIGH);
  analogWrite(right_2, s);
}
void rightBack(int p) {
  double s = 255*((0.01*p));
  digitalWrite(right_1, LOW);
  analogWrite(right_2, s);
}
void leftForward(int p) {
  double s = 255*(1 - (0.01*p));
  digitalWrite(left_1, HIGH);
  analogWrite(left_2, s);
}
void leftBack(int p) {
   double s = 255*((0.01*p));
  digitalWrite(left_1, LOW);
  analogWrite(left_2, s);
}

void delaySecond(int sec) {
  delay(1000 * sec);
}
