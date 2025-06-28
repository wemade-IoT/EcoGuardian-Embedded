//
// Created by Mathias Alejandro Jave Diaz on 10/06/25.
//

#ifndef MONITORINPLANTDEVICE_H
#define MONITORINPLANTDEVICE_H
#include "Device.h"
#include "HumidtySensor.h"
#include "LightSensor.h"
#include "WaterSensor.h"
#include <string>

#include "WaterDispensor.h"

class MonitorinPlantDevice : Device {
private:
    OneWire oneWire;
    DallasTemperature sensors;
    LightSensor lightSensor;
    HumiditySensor humiditySensor;
    WaterSensor waterSensor;
    WaterDispensor waterDispensor;
public:
    static const int LIGHT_PIN = 32;
    static const int WATER_PIN = 34;
    static const int HUMIDITY_SENSOR_PIN = 25;
    static const int WATER_DISPENSOR_PIN = 18;
    MonitorinPlantDevice(int lightPin = LIGHT_PIN,int waterPin = WATER_PIN, int humidityPin = HUMIDITY_SENSOR_PIN, int waterDispensorPin = WATER_DISPENSOR_PIN);
    void on(Event event) override;
    void handle(Command command) override;
    LightSensor getLightSensor();
    HumiditySensor getHumiditySensor();
    WaterSensor getWaterSensor();
    WaterDispensor& getWaterDispensor();
    DallasTemperature& getSensors();
    void init();
    void triggerLightSensorEvent();
    void triggerHumiditySensorEvent();
    void triggerWaterSensorEvent();
    void updateLightSensorValue();
    void updateHumiditySensorValue();
    void updateWaterSensorValue();
    void dispenseWater();
    void restart();
    void print(const std::string& message);


};

#endif //MONITORINPLANTDEVICE_H