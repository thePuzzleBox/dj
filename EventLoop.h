

#ifndef SFML_PROJECT_EVENTLOOP_H
#define SFML_PROJECT_EVENTLOOP_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "consts.h"
#include "IEntity.h"
#include "KeyboardState.h"
#include "GameState.h"
#include "States.h"
#include "View.h"
#include "Menu.h"
#include "Engine.h"
#include "Overlay.h"
#include "Sprite.h"
#include "Assets.h"

class EventLoop
{
public:
    void pollEvents();

    void update();

    void redrawFrame();

    void init();

    const sf::RenderWindow &getWindow() const;

private:
    float m_deltaTime = 0.f;
    sf::Clock m_clock;
    sf::RenderWindow m_window;
    View m_view;
    States m_states = States(m_window);
    Entities m_entities;
    std::shared_ptr<Doodler> m_p_doodler = std::make_shared<Doodler>(Doodler(m_states));
    Engine m_engine = Engine(m_p_doodler);
    Menu m_menu = Menu(m_states);
    Overlay m_overlay = Overlay(m_states);
    Sprite m_backgroundSprite = Sprite({
                                               Assets::BACKGROUND.length,
                                               Assets::BACKGROUND.data,
                                               {0.f, BACKGROUND_SPRITE_SIZE.y},
                                               false, true
                                       });

    void createWindow();

    void drawGameScreen();

    void drawMenuScreen();

    void restart();
};


#endif //SFML_PROJECT_EVENTLOOP_H
