
int left_1 = 2;
int left_2 = 3; // Analog
int right_1 = 4;
int right_2 = 5; // Analog
int red = 10;
int green = 11;
int blue = 12;

void setup() {
  Serial.begin(115200);
  
  pinMode(left_1, OUTPUT);
  pinMode(left_2, OUTPUT);
  pinMode(right_1, OUTPUT);
  pinMode(right_2, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(13, OUTPUT);
}
void loop() {
  if (Serial.available() > 0) {
    char cmd = Serial.read();
    if (cmd == 'w') {
      Go(0, 0);
      delaySecs(1);

      Go(255, 255);
    } else if (cmd == 's') {
      Go(0, 0);
      delaySecs(1);
      Go(-255,-255);
    } else if (cmd == 'a') {
      Go(0, 0);
    } else if (cmd == 'z') {
      Loff();
      dwH(red);
    } else if (cmd == 'x') {
      Loff();
      dwH(green);
    } else if (cmd == 'c') {
      Loff();
      dwH(blue);
    } else if (cmd == 'v') {
      Loff();
      dwH(red);
      dwH(green);
    } else if (cmd == 'b') {
      Loff();
      dwH(red);
      dwH(blue);
    } else if (cmd == 'n') {
      Loff();
      dwH(blue);
      dwH(green);
    }else if (cmd == 'm') {
      Loff();
      dwH(red);
      dwH(green);
      dwH(blue);
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

void Loff () {
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
}
void dwH (int n) {
  digitalWrite(n, HIGH);
}
void dwF (int n) {
  digitalWrite(n, LOW);
}

void delaySecs(int secs) {
  delay(1000 * secs);
}
