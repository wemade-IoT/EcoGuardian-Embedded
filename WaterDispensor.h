//
// Created by Mathias Alejandro Jave Diaz on 12/06/25.
//

#ifndef WATERDISPENSOR_H
#define WATERDISPENSOR_H
#include "Actuator.h"
#include <ESP32Servo.h>

class WaterDispensor : public Actuator {


public:
    Servo servo;
    int servoPin;
    int startPosition = 90;
    int dispensePosition = 0;
    static const int DISPENSE_WATER_COMMAND_ID = 3;
    static const int RESTART_WATER_COMMAND_ID = 4;
    static Command DISPENSE_WATER_COMMAND;
    static Command RESTART_WATER_COMMAND;
    WaterDispensor(int id, int servoPin, CommandHandler *handler = nullptr);
    void restart();
    void dispenseWater();
    void write(int position);
    void attach();
};

#endif //WATERDISPENSOR