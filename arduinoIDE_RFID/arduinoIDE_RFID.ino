#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 9
#define SS_PIN 10

MFRC522 rfid(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  Serial.println("RFID prêt à scanner une carte...");
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return;
  }

  // Lire l'UID
  String uid = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    uid += String(rfid.uid.uidByte[i], HEX);
  }
  uid.toUpperCase();  // Facultatif : selon format en DB

  Serial.println(uid);  // Envoyer l'UID vers Qt
  delay(1000);          // Attente pour la réponse

 

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}
