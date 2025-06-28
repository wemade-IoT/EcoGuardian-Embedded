//
// Created by Mathias Alejandro Jave Diaz on 9/06/25.
//

#ifndef HUMIDTYSENSOR_H
#define HUMIDTYSENSOR_H
#include "Sensor.h"
#include <DallasTemperature.h>

class HumiditySensor : public Sensor {
public:
    int sensorPin;
    static const int HUMIDITY_EVENT_ID = 1;
    static Event HUMIDITY_EVENT;

    HumiditySensor(int id, int pin, EventHandler *handler = nullptr);
    float getValue(DallasTemperature &sensors);

};

#endif //HUMIDTYSENSOR_H