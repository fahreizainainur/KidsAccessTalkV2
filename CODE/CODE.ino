#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(3, 2); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

int button1 = 4;
int button2 = 5;
int button3 = 6;
int button4 = 7;
int button5 = 8;
int button6 = 9;
int button7 = 10;
int button8 = 11;

const int pinLED = 13;

const int pinADC = A0;
float teganganBaterai = 0;

void setup() {
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(button5, INPUT_PULLUP);
  pinMode(button6, INPUT_PULLUP);
  pinMode(button7, INPUT_PULLUP);
  pinMode(button8, INPUT_PULLUP);

  mySoftwareSerial.begin(9600);
  Serial.begin(9600);

  delay(1000);

  Serial.println();
  Serial.println("DFPlayer Mini Demo");
  Serial.println("Initializing DFPlayer...");

  if (!myDFPlayer.begin(mySoftwareSerial)) {
    Serial.println("Unable to begin:");
    Serial.println("1.Please recheck the connection!");
    Serial.println("2.Please insert the SD card!");
    while (true);
  }
  Serial.println(F("DFPlayer Mini online."));

  myDFPlayer.setTimeOut(500);

  // Set volume
  myDFPlayer.volume(29); //Set volume value (0~30).
  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);

  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
  //digitalWrite(button1, LOW);
}

void loop() {
  int buttonState1 = digitalRead(button1);
  int buttonState2 = digitalRead(button2);
  int buttonState3 = digitalRead(button3);
  int buttonState4 = digitalRead(button4);
  int buttonState5 = digitalRead(button5);
  int buttonState6 = digitalRead(button6);
  int buttonState7 = digitalRead(button7);
  int buttonState8 = digitalRead(button8);

  int nilaiADC = analogRead(pinADC);
  float teganganADC = nilaiADC * (5.0 / 1023.0);
  teganganBaterai = teganganADC / 0.5238;

  Serial.print("Tegangan Baterai 2S: ");
  Serial.print(teganganADC);
  Serial.println(" V");

//  Serial.print("B1: ");
//  Serial.print(buttonState1);
//  Serial.print(" ");
//  Serial.print("B2: ");
//  Serial.print(buttonState2);
//  Serial.print(" ");
//  Serial.print("B3: ");
//  Serial.print(buttonState3);
//  Serial.print(" ");
//  Serial.print("B4: ");
//  Serial.print(buttonState4);
//  Serial.print(" ");
//  Serial.print("B5: ");
//  Serial.println(buttonState5);
//  Serial.print(" ");
//  Serial.print("B6: ");
//  Serial.println(buttonState6);
//  Serial.print(" ");
//  Serial.print("B7: ");
//  Serial.println(buttonState7);
//  Serial.print(" ");
//  Serial.print("B8: ");
//  Serial.println(buttonState8);
//  //Serial.print(" ");*/

  if (buttonState1 ==  LOW) {
    Serial.println("1 kepencet");
    myDFPlayer.playMp3Folder(1); // Play the sound associated with button1
    delay(2000);
  }
  else if (buttonState2 == LOW) {
    Serial.println("2 kepencet");
    myDFPlayer.playMp3Folder(2); // Play the sound associated with button2
    delay(2000);
  }
  else if (buttonState3 == LOW) {
    Serial.println("3 kepencet");
    myDFPlayer.playMp3Folder(3); // Play the sound associated with button3
    delay(2000);
  }
  else if (buttonState4 == LOW) {
    Serial.println("4 kepencet");
    myDFPlayer.playMp3Folder(4); // Play the sound associated with button4
    delay(2000);
  }
  else if (buttonState5 == LOW) {
    Serial.println("5 kepencet");
    myDFPlayer.playMp3Folder(5); // Play the sound associated with button5
    delay(2000);
  }
  else if (buttonState6 == LOW) {
    Serial.println("6 kepencet");
    myDFPlayer.playMp3Folder(6); // Play the sound associated with button6
    delay(2000);
  }
  else if (buttonState7 == LOW) {
    Serial.println("7 kepencet");
    myDFPlayer.playMp3Folder(7); // Play the sound associated with button7
    delay(2000);
  }
  else if (buttonState8 == LOW) {
    Serial.println("8 kepencet");
    myDFPlayer.playMp3Folder(8); // Play the sound associated with button8
    delay(2000);
  }

  if (teganganBaterai <= 7.2) {
    digitalWrite(pinLED, HIGH);
  } 
  else {
    digitalWrite(pinLED, LOW);
  }
}
