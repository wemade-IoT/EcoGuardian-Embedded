//
// Created by Mathias Alejandro Jave Diaz on 9/06/25.
//

#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

struct Event {
    int id;
    explicit Event(int id) : id(id) {}
    bool operator==(const Event &other) const {
        return id == other.id;
    }
};

class EventHandler {
public:
    virtual void on(Event event) = 0;
    virtual ~EventHandler() {}
};

#endif //EVENTHANDLER_H