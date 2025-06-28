//
// Created by Mathias Alejandro Jave Diaz on 9/06/25.
//

#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

struct Command {
    int id;
    explicit Command(int id) : id(id) {}
    bool operator==( const Command &other) const {
        return id == other.id;
    }
};

class CommandHandler {
public:
    virtual void handle(Command command) = 0;
    virtual ~CommandHandler() {}
};

#endif //COMMANDHANDLER_H