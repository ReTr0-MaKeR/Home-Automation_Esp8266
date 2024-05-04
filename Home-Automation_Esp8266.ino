#define BLYNK_TEMPLATE_ID "Template ID from blynk.cloud"
#define BLYNK_TEMPLATE_NAME "Template name from blynk.cloud"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
#define APP_DEBUG

#include "BlynkEdgent.h"

const int pinGPIO1 = 4; // GPIO pin connected to V0
const int pinGPIO2 = 5; // GPIO pin connected to V1
const int pinGPIO3 = 14; // GPIO pin connected to V2

void setup() {
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();

  pinMode(pinGPIO1, OUTPUT);
  pinMode(pinGPIO2, OUTPUT);
  pinMode(pinGPIO3, OUTPUT);
}

void loop() {
  BlynkEdgent.run();
}

BLYNK_WRITE(V0) {
  int value = param.asInt();
  digitalWrite(pinGPIO1, value);
  Serial.print("GPIO 1 status: ");
  Serial.println(value);
}

BLYNK_WRITE(V1) {
  int value = param.asInt();
  digitalWrite(pinGPIO2, value);
  Serial.print("GPIO 2 status: ");
  Serial.println(value);
}

BLYNK_WRITE(V2) {
  int value = param.asInt();
  digitalWrite(pinGPIO3, value);
  Serial.print("GPIO 3 status: ");
  Serial.println(value);
}
