//hayder
/*#include <SPI.h>
#include <MFRC522.h>

// Définition des pins
#define RST_PIN 9
#define SS_PIN 10

MFRC522 rfid(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  Serial.println("RFID prêt à scanner une carte...");
}
*/
/*void loop() {
  // Vérifier si une nouvelle carte est présente
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return;
  }

  // Lire l'UID
  String uid = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    if (rfid.uid.uidByte[i] < 0x10) {
      uid += "0"; // Ajouter un 0 devant si besoin
    }
    uid += String(rfid.uid.uidByte[i], HEX);
  }
  uid.toUpperCase(); // Mettre en majuscule

  // Afficher l'UID sur le Serial Monitor
  Serial.println(uid);

  delay(1000); // Petite pause

  // Mettre fin à la communication avec la carte
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}*/

/*void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return;
  }

  String uid = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    if (rfid.uid.uidByte[i] < 0x10) {
      uid += "0";
    }
    uid += String(rfid.uid.uidByte[i], HEX);
  }
  uid.toUpperCase();

  Serial.println(uid);  // ✅ ENVOIE JUSTE L'UID
  delay(1000);

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}

*/
//rahma
/*const int bouton1Pin = 2;
const int bouton2Pin = 3;

void setup() {
  // Initialise les pins en entrée
  pinMode(bouton1Pin, INPUT_PULLUP); // Utilisation de la résistance interne Pull-Up
  pinMode(bouton2Pin, INPUT_PULLUP);

  // Initialisation du port série pour affichage
  Serial.begin(9600);
}

void loop() {
  // Lecture de l'état des boutons
  int bouton1State = digitalRead(bouton1Pin);
  int bouton2State = digitalRead(bouton2Pin);

  // Vérification si le bouton est appuyé
  if (bouton1State == LOW) { // LOW car Pull-Up activé
    Serial.println("button1_pressed");
    delay(200); // Anti-rebond simple
  }

  if (bouton2State == LOW) {
    Serial.println("button2_pressed");
    delay(200); // Anti-rebond simple
  }
}*/
//ilyes
/*#include <Servo.h>

Servo mon_servo; // Create the servo object
int pos = 0;
bool moveServo = false; // Flag to control movement

void setup() {
  mon_servo.attach(8); // Attach the servo to pin 8
  Serial.begin(9600);  // Start serial communication
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read(); // Read the incoming byte
    if (command == '1') {
      moveServo = true;
    } else if (command == '0') {
      moveServo = false;
    }
  }

  if (moveServo) {
    // Move the servo from 0° to 180°
    for (pos = 0; pos <= 180; pos++) {
      if (!moveServo) break; // Stop immediately if '0' received
      mon_servo.write(pos);
      delay(15);
      checkSerial(); // Check serial input during movement
    }

    // Move the servo from 180° back to 0°
    for (pos = 180; pos >= 0; pos--) {
      if (!moveServo) break; // Stop immediately if '0' received
      mon_servo.write(pos);
      delay(15);
      checkSerial(); // Check serial input during movement
    }
  }
}

// Helper function to check serial input while moving
void checkSerial() {
  if (Serial.available()) {
    char command = Serial.read();
    if (command == '0') {
      moveServo = false;
    }
  }
}*/
//hayder_ilyes
/*#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define RST_PIN 9
#define SS_PIN 10

MFRC522 rfid(SS_PIN, RST_PIN);
Servo mon_servo;
//hayder_ilyes
void setup() {
  Serial.begin(9600);     // Serial used by Qt
  SPI.begin();
  rfid.PCD_Init();
  mon_servo.attach(8);
  mon_servo.write(0);
  Serial.println("Ready to scan...");
}

void loop() {
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    String uid = "";
    for (byte i = 0; i < rfid.uid.size; i++) {
      if (rfid.uid.uidByte[i] < 0x10) uid += "0";
      uid += String(rfid.uid.uidByte[i], HEX);
    }
    uid.toUpperCase();

    Serial.println(uid);  // ✅ Send UID to Qt via Serial

    // ❌ Block servo if UID is F37C86F5
    if (uid != "F37C86F5") {
      mon_servo.write(180);
      delay(1000);
      mon_servo.detach();
    } else {
      Serial.println("Access blocked for UID: F37C86F5");
    }

    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
    delay(1000); // Anti-repetition delay
  }
}
*/
//yassmin_douaa
/*#include <Wire.h> 
#include <LiquidCrystal_I2C.h>  // مكتبة شاشة LCD مع I2C

LiquidCrystal_I2C lcd(0x27, 16, 2);  // عنوان I2C للشاشة 0x27 مع حجم 16x2

int scoreEST = 0;  // النتيجة لفريق EST
int scoreCA = 0;   // النتيجة لفريق CA

// تعريف الدبابيس الخاصة بالكواشف
const int trig1 = 4;
const int echo1 = 5;
const int trig2 = 6;
const int echo2 = 3;

void setup() {
  lcd.begin(16, 2);
  lcd.backlight();
  
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);

  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);

  lcd.setCursor(0, 0);
  lcd.print("EST: " + String(scoreEST));
  lcd.setCursor(0, 1);
  lcd.print("CA: " + String(scoreCA));
}

long readDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2;  // المسافة بالسنتيمتر
  return distance;
}

void loop() {
  long distance1 = readDistance(trig1, echo1);
  long distance2 = readDistance(trig2, echo2);

  if (distance1 < 10 && distance1 > 0) {
    scoreEST++;
    updateLCD();
    delay(2000);  // نزيد شوية وقت باش ما يعاودش يحتسب نفس الهدف
  }

  if (distance2 < 10 && distance2 > 0) {
    scoreCA++;
    updateLCD();
    delay(2000);
  }

  delay(200);  // تأخير خفيف لتجنب القراءة الزايدة
}

void updateLCD() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("EST: " + String(scoreEST));
  lcd.setCursor(0, 1);
  lcd.print("CA: " + String(scoreCA));
}
*/

