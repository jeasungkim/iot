//ESP32 for bluetooth test
#include <BluetoothSerial.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run 'make manuconfig' to and enable it
#endif

const int LED = 2;
char data = 0;

BluetoothSerial BTSerial;


void setup() {
  Serial.begin(9000);
  BTSerial.begin("ESPname");
  pinMode(LED, OUTPUT);
}

void loop() {
  if(BTSerial.available()){
    data = BTSerial.read();
    Serial.write(data);
    switch(data)
    {
      case '1': digitalWrite(LED, HIGH)
      break;

       case '0': digitalWrite(LED, LOW)
      break;
    }
  }

  if(serial.available())
  {
    BTSerial.write(Serial.read(1));

  }
  delay(1);

}