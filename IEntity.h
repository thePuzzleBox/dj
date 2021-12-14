
#ifndef SFML_PROJECT_IENTITY_H
#define SFML_PROJECT_IENTITY_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "IPhysicsObject.h"
#include "consts.h"

class IEntity : public IPhysicsObject, public sf::Drawable, public sf::Transformable
{
public:
    virtual void updatePosition(float deltaTime)
    {
        (void) &deltaTime;
    };

    virtual void setPlatformIntersection(float nextFloor)
    {
        (void) &nextFloor;
    };

    virtual bool getFallingState() const
    {
        return false;
    };

    virtual void eventHandler(const sf::Event &event)
    {
        (void) &event;
    };

private:
    virtual void checkCollision() {};
};

using Entities = std::vector<std::shared_ptr<IEntity>>;

#endif //SFML_PROJECT_IENTITY_H
