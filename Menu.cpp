
#include "Menu.h"
#include <locale>
#include "Assets.h"

Menu::Menu(States &stateMediator) : states(stateMediator)
{
    if (font.loadFromMemory(Assets::FONT.data, Assets::FONT.length))
    {
        createLogo();
        createScore();
        createStartButton();
        createRestartButton();
        createExitButton();
    } else
        exit(EXIT_FAILURE);
}

void Menu::createStartButton()
{
    startButton = make_unique<Sprite>(Sprite({
                                                              Assets::PLAY_BUTTON.length,
                                                              Assets::PLAY_BUTTON.data,
                                                              BUTTON_SPRITE_SIZE,
                                                              false, true
                                                      }));
    startButton->setPosition({WINDOW_WIDTH / 2, WINDOW_HEIGHT / 1.5f});
}

void Menu::createExitButton()
{
    const float topOffset = startButton->getPosition().y + startButton->getSize().y + BASE_MARGIN * 2;
    exitButton = make_unique<Sprite>(Sprite({
                                                             Assets::CANCEL_BUTTON.length,
                                                             Assets::CANCEL_BUTTON.data,
                                                             BUTTON_SPRITE_SIZE,
                                                             false, true
                                                     }));
    exitButton->setPosition({WINDOW_WIDTH / 2, topOffset});
}

void Menu::createRestartButton()
{
    restartButton = make_unique<Sprite>(Sprite({
                                                                Assets::RESTART_BUTTON.length,
                                                                Assets::RESTART_BUTTON.data,
                                                                BUTTON_SPRITE_SIZE,
                                                                false, true
                                                        }));
    restartButton->setPosition({WINDOW_WIDTH / 2, WINDOW_HEIGHT / 1.5f});
}

void Menu::createLogo()
{
    logo.setFont(font);
    logo.setString(WINDOW_TITLE);
    logo.setCharacterSize(LOGO_TEXT_SIZE);
    logo.setFillColor(sf::Color::Black);
    const sf::FloatRect &bounds = logo.getLocalBounds();
    logo.setOrigin({bounds.left + bounds.width / 2, bounds.top + bounds.height / 2});
    logo.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 8);
}

void Menu::createScore()
{
    score.setFont(font);
    score.setCharacterSize(SCORE_TEXT_SIZE);
    score.setFillColor(sf::Color::Black);
    updateMenu();
    score.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 3);
}


void Menu::draw(sf::RenderTarget &target, sf::RenderStates m_states) const
{
    const EState state = states.getState();
    switch (state)
    {
        case EState::MAIN_MENU:
            target.draw(*startButton, m_states);
            break;
        case EState::GAME_OVER:
            target.draw(score, m_states);
            target.draw(*restartButton, m_states);
            break;
        default:
            break;
    }
    target.draw(logo, m_states);
    target.draw(*exitButton, m_states);
}

void Menu::eventHandler(sf::Event &event, const sf::Vector2f &mousePosition, const function<void()> &callback)
{
    if (event.type != sf::Event::MouseButtonPressed)
    {
        return;
    }
    const sf::FloatRect &startButtonBounds = startButton->getBoundingCoordinates();
    const sf::FloatRect &exitButtonBounds = exitButton->getBoundingCoordinates();
    const sf::FloatRect &restartButtonBounds = restartButton->getBoundingCoordinates();
    const EState state = states.getState();
    if (startButtonBounds.contains(mousePosition) && state == EState::MAIN_MENU)
    {
        states.setState(EState::GAME_PROCESS);
    } else if (restartButtonBounds.contains(mousePosition) && state == EState::GAME_OVER)
    {
        states.setState(EState::GAME_PROCESS);
        callback();
    } else if (exitButtonBounds.contains(mousePosition))
    {
        exit(EXIT_SUCCESS);
    }
}

void Menu::updateMenu()
{
    const auto m_score = static_cast<int>(states.getScore() * SCORE_MULTIPLIER);
    score.setString("your score: " + to_string(m_score));
    updateScoreOrigin();
}


void Menu::updateScoreOrigin()
{
    const sf::FloatRect &bounds = score.getLocalBounds();
    score.setOrigin({bounds.left + bounds.width / 2, bounds.top + bounds.height / 2});
}