//
// Created by Mathias Alejandro Jave Diaz on 10/06/25.
//

#ifndef DEVICE_H
#define DEVICE_H
#include "CommandHandler.h"
#include "EventHandler.h"

class Device : public EventHandler, public CommandHandler {
public:
    virtual void on(Event event) override = 0;
    virtual void handle(Command command) override = 0;
    virtual ~Device() = default;
};

#endif //DEVICE_H