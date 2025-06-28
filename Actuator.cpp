//
// Created by Mathias Alejandro Jave Diaz on 9/06/25.
//
#include "Actuator.h"
Actuator::Actuator(int id, CommandHandler *handler) : id(id), handler(handler) {}

int Actuator::getId() {
    return id;
}
void Actuator::handle(Command command) {
    if (this->handler != nullptr) {
        this->handler->handle(command);
    }
}

void Actuator::setHandler(CommandHandler *handler) {
    this->handler = handler;
}


