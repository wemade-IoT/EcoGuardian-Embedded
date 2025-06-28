//
// Created by Mathias Alejandro Jave Diaz on 9/06/25.
//

#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H
#include "Sensor.h"

class LightSensor : public Sensor {
public:
    int pin;
    static const int LIGHT_EVENT_ID = 2;
    static const Event LIGHT_EVENT;

    LightSensor(int id, int pin, EventHandler *handler = nullptr);
    float getValue();

};
#endif //LIGHTSENSOR_H