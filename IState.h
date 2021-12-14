
#ifndef SFML_PROJECT_ISTATE_H
#define SFML_PROJECT_ISTATE_H
#include <SFML/Graphics.hpp>
#include "enums.h"

class IState
{
public:
    virtual void eventHandler(const sf::Event &event) = 0;
};

#endif //SFML_PROJECT_ISTATE_H
