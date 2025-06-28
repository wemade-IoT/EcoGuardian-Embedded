//
// Created by Mathias Alejandro Jave Diaz on 9/06/25.
//
#include "Sensor.h"

Sensor::Sensor(int id, int pin, EventHandler *handler): id(id), pin(pin), handler(handler) {}

int Sensor::getId() {
    return id;
}

void Sensor::on(Event event) {
    if (this->handler != nullptr) {
        this->handler->on(event);
    }
}

void Sensor::setHandler(EventHandler *handler) {
    this->handler = handler;
}


