

#ifndef SFML_PROJECT_STATES_H
#define SFML_PROJECT_STATES_H
#include "State.h"
#include <map>

class States
{
private:
    std::map<State, bool> states;

public:
    bool isEnabled(State state);
    void enableState(State state);
    void disableState(State state);
};

#endif
