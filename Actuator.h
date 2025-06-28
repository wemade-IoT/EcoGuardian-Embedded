//
// Created by Mathias Alejandro Jave Diaz on 9/06/25.
//

#ifndef ACTUATOR_H
#define ACTUATOR_H
#include "CommandHandler.h"

class Actuator : public CommandHandler {
protected:
    CommandHandler *handler;
    int id;
public:
    Actuator(int id, CommandHandler *handler);
    int getId();
    void handle(Command command) override;
    void setHandler(CommandHandler *handler);
};

#endif //ACTUATOR_H