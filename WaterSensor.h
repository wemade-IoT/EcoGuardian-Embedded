//
// Created by Mathias Alejandro Jave Diaz on 9/06/25.
//

#ifndef WATERSENSOR_H
#define WATERSENSOR_H
#include "Sensor.h"

class WaterSensor final : public Sensor {
public:
    int pin;
    static const int WATER_EVENT_ID = 0;
    static Event WATER_EVENT;

    WaterSensor(int id, int pin, EventHandler *handler = nullptr);
    float getValue();

};

#endif //WATERSENSOR_H