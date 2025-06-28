//
// Created by Mathias Alejandro Jave Diaz on 10/06/25.
//

#include "WaterSensor.h"
#include <Arduino.h>

Event WaterSensor::WATER_EVENT = Event(WATER_EVENT_ID);
WaterSensor::WaterSensor(int id, int pin, EventHandler *handler) : Sensor(id, pin, handler), pin(pin){}

float WaterSensor::getValue() {
    float voltage = analogRead(pin);
    float value = voltage / 2703.0;
    return value * 100.0;
}

