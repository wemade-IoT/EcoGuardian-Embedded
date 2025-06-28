//
// Created by Mathias Alejandro Jave Diaz on 9/06/25.
//

#ifndef SENSOR_H
#define SENSOR_H
#include "EventHandler.h"

class Sensor  : public EventHandler {
protected:
    int id;
    int pin;
    EventHandler* handler;
public:
    Sensor(int id, int pin, EventHandler* handler);
    int getId();
    void on(Event event) override;
    void setHandler(EventHandler* handler);
};

#endif //SENSOR_H