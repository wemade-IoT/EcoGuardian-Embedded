//
// Created by Mathias Alejandro Jave Diaz on 10/06/25.
//

#include "LightSensor.h"
#include <Arduino.h>

const Event LightSensor::LIGHT_EVENT = Event(LIGHT_EVENT_ID);
LightSensor::LightSensor(int id, int pin, EventHandler *handler) : Sensor(id, pin, handler), pin(pin) {}
float LightSensor::getValue() {
  float voltage = analogRead(pin);
  float value = voltage / 2703.0;
  return value * 100.0;
}
