//
// Created by Mathias Alejandro Jave Diaz on 10/06/25.
//

#include "HumidtySensor.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include "Arduino.h"

Event HumiditySensor::HUMIDITY_EVENT = Event(HUMIDITY_EVENT_ID);
HumiditySensor::HumiditySensor(int id, int pin, EventHandler *handler) : Sensor(id, pin, handler), sensorPin(pin) {}
float HumiditySensor::getValue(DallasTemperature &sensors) {
    sensors.requestTemperatures();
    delay(1000);
    float humidity = sensors.getTempCByIndex(0);
    return humidity;
}

