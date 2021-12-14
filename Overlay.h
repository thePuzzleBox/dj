

#ifndef SFML_PROJECT_OVERLAY_H
#define SFML_PROJECT_OVERLAY_H

#include "States.h"

class Overlay : public sf::Drawable
{
public:
    explicit Overlay(States &stateMediator);

    void updateOverlay(float nextY, float deltaTime);

private:
    States &states;
    sf::Font font;
    sf::Text score;
    sf::Text fps;

    void createScoreCounter();

    void createFrameRateCounter();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void updateOverlayPosition(float nextY);

    void updateOverlayStrings(float deltaTime);
};


#endif //SFML_PROJECT_OVERLAY_H
