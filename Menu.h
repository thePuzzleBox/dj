
#ifndef SFML_PROJECT_MENU_H
#define SFML_PROJECT_MENU_H

#include <SFML/Graphics.hpp>
#include "States.h"
#include "Sprite.h"
#include "consts.h"

using namespace std;

class Menu : public sf::Drawable
{

public:
    explicit Menu(States &stateMediator);
    void eventHandler(sf::Event &event, const sf::Vector2f &mousePosition, const function<void()> &callback);
    void updateMenu();

private:
    States &states;
    sf::Font font;
    sf::Text logo;
    sf::Text score;
    unique_ptr<Sprite> startButton;
    unique_ptr<Sprite> exitButton;
    unique_ptr<Sprite> restartButton;

    void createStartButton();
    void createRestartButton();
    void createExitButton();
    void createLogo();
    void createScore();
    void updateScoreOrigin();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif //SFML_PROJECT_MENU_H
