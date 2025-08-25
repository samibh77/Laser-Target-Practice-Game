#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialisation de l'écran LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); // 16 columns and 2 rows

Servo servo1;
Servo servo2;
Servo servo3;

int score = 0;
int laser = 6;

const int LED1 = 2;
const int LED2 = 3; 
const int LED3 = 4;

const int LDR1 = A0;
const int LDR2 = A1;
const int LDR3 = A2;

const int SERVO_PIN1 = 9;
const int SERVO_PIN2 = 10;
const int SERVO_PIN3 = 11;

void setup() {
  // Initialisation des servos et autres composants
  Serial.begin(9600);
  servo1.attach(SERVO_PIN1);
  servo2.attach(SERVO_PIN2);
  servo3.attach(SERVO_PIN3);
  
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(laser, OUTPUT);
  digitalWrite(laser, HIGH);

  initServo();

  // Initialisation de l'écran LCD
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("HIGH Score : 10");
  lcd.setCursor(0, 1);
  lcd.print("YOUR Score : 0");
}

void loop() {
  int randomNum = random(0, 3);  // Declare the variable here

  if (randomNum == 0) {
    moveDisks1Randomly();
    checkLaserHit1();
  } else if (randomNum == 1) {
    moveDisks2Randomly();
    checkLaserHit2();
  } else {
    moveDisks3Randomly();
    checkLaserHit3();
  }

  delay(1000);  // Pause for readability
}

void moveDisks1Randomly() {
  servo1.write(45);
  digitalWrite(LED1, LOW);
  delay(1000);  
  servo1.write(120); 
  digitalWrite(LED1, HIGH);
  delay(1000); 
  servo1.write(45);
  digitalWrite(LED1, LOW);
}

void moveDisks2Randomly() {
  servo2.write(30);
  digitalWrite(LED2, LOW);
  delay(1000);  
  servo2.write(110); 
  digitalWrite(LED2, HIGH);
  delay(1000); 
  servo2.write(30);
  digitalWrite(LED2, LOW);
}

void moveDisks3Randomly() {
  servo3.write(20);
  digitalWrite(LED3, LOW);
  delay(1000);  
  servo3.write(90); 
  digitalWrite(LED3, HIGH);
  delay(1000);  
  servo3.write(20);
  digitalWrite(LED3, LOW);
}

void checkLaserHit1() {
  int ldrValue1 = analogRead(LDR1);
  if (ldrValue1 <= 900) {
    score += 0;
  } else {
    score += 1;
  }
  updateLCD();
}

void checkLaserHit2() {
  int ldrValue2 = analogRead(LDR2);
  if (ldrValue2 <= 900) {
    score += 0;
  } else {
    score += 1;
  }
  updateLCD();
}

void checkLaserHit3() {
  int ldrValue3 = analogRead(LDR3);
  if (ldrValue3 <= 900) {
    score += 0;
  } else {
    score += 1;
  }
  updateLCD();
}

void initServo() {
  servo1.write(45);
  servo2.write(30);
  servo3.write(20);  
}

void updateLCD() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("HIGH Score: 10");
  lcd.setCursor(0, 1);
  lcd.print("YOUR Score: ");
  lcd.print(score);
}
