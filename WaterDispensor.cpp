//
// Created by Mathias Alejandro Jave Diaz on 12/06/25.
//
#include "WaterDispensor.h"
Command WaterDispensor::DISPENSE_WATER_COMMAND = Command(DISPENSE_WATER_COMMAND_ID);
Command WaterDispensor::RESTART_WATER_COMMAND = Command(RESTART_WATER_COMMAND_ID);
WaterDispensor::WaterDispensor(int id, int servoPin, CommandHandler *handler) : Actuator(id, handler), servoPin(servoPin) {
}
void WaterDispensor::write(int position) {
    servo.write(position);
}

void WaterDispensor::attach() {
    servo.attach(servoPin,500, 2400);
}

void WaterDispensor::dispenseWater() {
    write(dispensePosition);
}

void WaterDispensor::restart() {
    write(startPosition);
}

