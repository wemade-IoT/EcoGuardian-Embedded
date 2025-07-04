//
// Created by Mathias Alejandro Jave Diaz on 10/06/25.
//
#include "MonitorinPlantDevice.h"
#include <Arduino.h>
MonitorinPlantDevice::MonitorinPlantDevice(int id, int lightPin, int waterPin, int humidityPin, int waterDispensorPin)
: id(id),
  oneWire(humidityPin),
  sensors(&oneWire),
  lightSensor(2, lightPin),
  humiditySensor(1, humidityPin),
  waterSensor(3, waterPin),
  waterDispensor(4, waterDispensorPin)
{}

int MonitorinPlantDevice::getId() const {
    return id;
}

HumiditySensor MonitorinPlantDevice::getHumiditySensor() {
    return humiditySensor;
}

LightSensor MonitorinPlantDevice::getLightSensor() {
    return lightSensor;
}

WaterSensor MonitorinPlantDevice::getWaterSensor() {
    return waterSensor;
}

WaterDispensor& MonitorinPlantDevice::getWaterDispensor() {
    return waterDispensor;
}

DallasTemperature& MonitorinPlantDevice::getSensors() {
    return sensors;
}

void MonitorinPlantDevice::handle(Command command) {
   if (command.id == WaterDispensor::DISPENSE_WATER_COMMAND_ID) {
       dispenseWater();
   }
    else if (command.id == WaterDispensor::RESTART_WATER_COMMAND_ID) {
         restart();
    }
}

void MonitorinPlantDevice::on(Event event) {
    if (event.id == LightSensor::LIGHT_EVENT_ID) {
        updateLightSensorValue();
    } else if (event.id == WaterSensor::WATER_EVENT_ID) {
       updateWaterSensorValue();
    } else if (event.id == HumiditySensor::HUMIDITY_EVENT_ID) {
       updateHumiditySensorValue();
    }
}

void MonitorinPlantDevice::print(const std::string &message) {
    Serial.println(message.c_str());
}

void MonitorinPlantDevice::init() {
    Serial.begin(115200);
    print("Ready!");
    sensors.begin();
    getWaterDispensor().attach();
}


void MonitorinPlantDevice::dispenseWater() {
    getWaterDispensor().dispenseWater();
}

void MonitorinPlantDevice::restart() {
    getWaterDispensor().restart();
}




void MonitorinPlantDevice::triggerHumiditySensorEvent() {
    on(HumiditySensor::HUMIDITY_EVENT);
}

void MonitorinPlantDevice::triggerLightSensorEvent() {
    on(LightSensor::LIGHT_EVENT);
}

void MonitorinPlantDevice::triggerWaterSensorEvent() {
    on(WaterSensor::WATER_EVENT);
}

void MonitorinPlantDevice::updateLightSensorValue() {
    float value = lightSensor.getValue();
    print("Light Sensor Value: ");
    print(std::to_string(value));
}

void MonitorinPlantDevice::updateHumiditySensorValue() {
    float value = humiditySensor.getValue(sensors);
    print("Humidity Sensor Value: ");
    print(std::to_string(value));
}

void MonitorinPlantDevice::updateWaterSensorValue() {
    float value = waterSensor.getValue();
    if (value >= 50) {
        print("Dispensing water...");
        handle(WaterDispensor::DISPENSE_WATER_COMMAND);
    }else {
        handle(WaterDispensor::RESTART_WATER_COMMAND);
    }
    print("Water Sensor Value: ");
    print(std::to_string(value));
}
