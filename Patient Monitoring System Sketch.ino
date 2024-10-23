#include <Wire.h>                  
#include "RTClib.h"                 
#include <Adafruit_GFX.h>            
#include <Adafruit_SSD1306.h>        
#include <OneWire.h>              
#include <DallasTemperature.h>    
#include <SoftwareSerial.h>
#include <PulseSensorPlayground.h> 
#include <SD.h>                  
#include <SPI.h>  

Adafruit_SSD1306 oled(128, 64, &Wire, -1);

RTC_DS3231 rtc;

OneWire oneWire(2);   
DallasTemperature tempSensor(&oneWire); 

SoftwareSerial SIM900(12, 13);

File dataFile; 
                                           
PulseSensorPlayground pulseSensor;

String name = "Stiven Janku";
String nhs = "34532";
String phone = "+4407576696967";
String time;
String temp;
String temp1;
String date;
String heart;

int maxTemp = 26;
int maxRate = 200;

void(* resetFunc) (void) = 0;

static unsigned long timeout = 0;

void setup() {
  Serial.begin(19200);
  SIM900.begin(19200);
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  rtc.begin();
  SD.begin(53);
  tempSensor.begin();    
  tempSensor.setResolution(12);
  temp.reserve(10); 
  time.reserve(10); 
  oled.display();
  delay(2000);         
  oled.clearDisplay(); 
  if (rtc.lostPower())  {
   rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  pulseSensor.analogInput(0);
  pulseSensor.setThreshold(600);  
  pulseSensor.begin();
}

void loop() {
  DateTime now = rtc.now();
  tempSensor.requestTemperatures();        
  float tempCelsius = tempSensor.getTempCByIndex(0);  
  temp  = String(tempCelsius, 1) + (char(247)) + "C";
  temp1  = String(tempCelsius, 1) + "*C";

  float myBPM = pulseSensor.getBeatsPerMinute();
  if (pulseSensor.sawStartOfBeat()) {            
    myBPM = myBPM;
    heart = String(myBPM,0) + "BPM";                   
  }

  oledisplay();

  if (millis() - timeout > 10000) {
      saveData();
      timeout = millis();
   }

  if (tempCelsius > maxTemp || myBPM > maxRate){
      sendSMS();
      saveDataSMS();
      oledSentSMS();
       heart = "--";
      delay(20000);
      resetFunc();
    }
}

void sendSMS() {

  SIM900.print("AT+CMGF=1\r"); 
  delay(100);

  SIM900.println("AT+CMGS=\"+447576696967\""); 
  delay(100);
  
  SIM900.println("WARNING!"); 
  delay(100);

  SIM900.print("Time: "); 
  delay(100);

  SIM900.println(time); 
  delay(100);
  
  SIM900.print("Date: "); 
  delay(100);

  SIM900.println(date); 
  delay(100);
  
  SIM900.print("Patient: "); 
  delay(100);

  SIM900.println(name); 
  delay(100);

  SIM900.print("NHS Number: "); 
  delay(100);

  SIM900.println(nhs); 
  delay(100);

  SIM900.print("Temperature: "); 
  delay(100);

  SIM900.println(temp1); 
  delay(100);

  SIM900.print("Heart Rate: "); 
  delay(100);
  
  SIM900.println(heart); 
  delay(100);

  SIM900.println((char)26); 
  delay(100);
  SIM900.println();

  delay(5000); 
}

void oledisplay() {
  DateTime now = rtc.now();
  time = "";
  time += now.hour();
  time += ':';
  time += now.minute();
  time += ':';
  time += now.second();

  date = "";
  date += now.day();
  date += '/';
  date += now.month();
  date += '/';
  date += now.year();

  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setTextColor(WHITE);
  oled.setCursor(0, 0);
  oled.print(date);
  
  oled.setCursor(80, 0);
  oled.print(time);

  oled.setCursor(0, 13);
  oled.print("Patient:");
  oled.print(name);
  
  oled.setCursor(0, 26);
  oled.print("NHS Number:");
  oled.print(nhs);

  oled.setCursor(0, 39);
  oled.print("Temp: ");
  oled.print(temp);
  
  oled.setCursor(0, 52);
  oled.print("Heart Rate: ");
  oled.print(heart);
  
  oled.display();
}

void oledSentSMS(){
  oled.clearDisplay();
  oled.setTextSize(2);
  oled.setTextColor(WHITE);
  oled.setCursor(0, 0);
  oled.print("Message \nhas been \nsent to \nNHS");
  oled.display();
}

void saveData() {
  dataFile = SD.open("data.txt", FILE_WRITE);
  dataFile.print("Patient: ");
  dataFile.println(name);
    
  dataFile.print("NHS Number: ");
  dataFile.println(nhs);

  dataFile.print("Date: ");
  dataFile.println(date);
    
  dataFile.print("Time: ");
  dataFile.println(time);

  dataFile.print("Temperature: ");
  dataFile.println(temp1);
  
  dataFile.print("Heart Rate: ");
  dataFile.println(heart);

  dataFile.println("\n\n************************************************************************************\n\n");

  dataFile.close();
}

void saveDataSMS() {
  dataFile = SD.open("data.txt", FILE_WRITE);
  
  dataFile.print("\n\n************************************************************************************\n\n");
  dataFile.println("************************************************************************************");    
  dataFile.print("The message has been sent to the following number: ");
  dataFile.println(phone);
  
  dataFile.print("Date: ");
  dataFile.println(date);
    
  dataFile.print("Time: ");
  dataFile.println(time);

  dataFile.println("************************************************************************************");  
  dataFile.println("\n\n************************************************************************************\n\n");

  dataFile.close();
}
