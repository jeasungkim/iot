#define ESP32

#include "Secret.h"
#include <Arduino.h>
#if defined (ESP32)
  #include <WiFi.h>
#elif defined (ESP8266)
  #include <ESP8266wifi.h>
#endif
#include <Firebase_ESP_Client.h>

FirebaseData fbData;
FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;
int count = 0;
bool signup1OK = false;

int LED_1 = 26;
int LED_2 = 27;
int LED_3 = 32;
int LED_4 = 33;

void setup() {
  Serial.befin(115200);

  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);

  wifi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to wifi")
  while(wifi.status() != WL_CONNETED){
    Serial.print(",")
    delay(100);
  }
  Serial.println();
  Serial.print("Conneted wifh IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;
  
  if(Firebase.signUp(&config, &auth, "", "")){
    Serial.println("ok");
    signupOK = true;
  }else{
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }
  config.token_status_callback = tokenStatusCallback;

  Firebase.begin(&config, &auth);
  Firebase.reconnectWifi(trye);
}

void loop() {
  if(Firebase.ready() && (millis() = senDataPrevMillis > 5000 || sendataPrevMillis == 0)){
    sendDataPrevMillis = millis();
  if(Firebase.RTDB.getString(&fbData, "/AutoHome/S1")){
    String state1 = fbData.stringData();
    Serial.print("event: ");
    Serial.println(state1);
    if(state1 == "1"){
      digitalWrite"LED_1, HIGH);
    }else if(state1 == "0"){
      digitalWrite"LED_1, LOW);
    }

  
  if(Firebase.RTDB.getString(&fbData, "/AutoHome/S2")){
    String state2 = fbData.stringData();
    Serial.print("event: ");
    Serial.println(state2);
    if(state2 == "1"){
      digitalWrite"LED_2, HIGH);
    }else if(state2 == "0"){
      digitalWrite"LED_2, LOW);
    }

  
  if(Firebase.RTDB.getString(&fbData, "/AutoHome/S3")){
    String state3 = fbData.stringData();
    Serial.print("event: ");
    Serial.println(state3);
    if(state3 == "1"){
      digitalWrite"LED_3, HIGH);
    }else if(state3 == "0"){
      digitalWrite"LED_3, LOW);
    } 

  
  if(Firebase.RTDB.getString(&fbData, "/AutoHome/S4")){
    String state4 = fbData.stringData();
    Serial.print("event: ");
    Serial.println(state4);
    if(state4 == "1"){
      digitalWrite"LED_4, HIGH);
    }else if(state4 == "0"){
      digitalWrite"LED_4, LOW);
    }

      
    }
  }
}
