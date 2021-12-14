
#include "Overlay.h"
#include "consts.h"
#include "Assets.h"

Overlay::Overlay(States &stateMediator) : states(stateMediator)
{
    if (font.loadFromMemory(Assets::FONT.data, Assets::FONT.length))
    {
        updateOverlayStrings(0.f);
        createScoreCounter();
        createFrameRateCounter();
    } else
        std::exit(EXIT_FAILURE);
}

void Overlay::createScoreCounter()
{
    score.setFont(font);
    score.setCharacterSize(GAME_SCORE_TEXT_SIZE);
    score.setFillColor(sf::Color::Black);
    score.setPosition(BASE_MARGIN / 2, 0);
}

void Overlay::createFrameRateCounter()
{
    fps.setFont(font);
    fps.setCharacterSize(GAME_SCORE_TEXT_SIZE);
    fps.setFillColor(sf::Color::Black);
    fps.setPosition(WINDOW_WIDTH - fps.getLocalBounds().width / 4, 0);
}

void Overlay::updateOverlay(float nextY, float deltaTime)
{
    updateOverlayPosition(nextY);
    updateOverlayStrings(deltaTime);
}

void Overlay::updateOverlayPosition(float nextY)
{
    const float scoreY = nextY - WINDOW_HEIGHT / 2;
    score.setPosition(score.getPosition().x, scoreY);

    const float fpsY = nextY - WINDOW_HEIGHT / 2;
    fps.setPosition(fps.getPosition().x, fpsY);
}

void Overlay::updateOverlayStrings(float deltaTime)
{
    const auto m_score = static_cast<int>(states.getScore() * SCORE_MULTIPLIER);
    score.setString("score: " + std::to_string(m_score));

    const auto m_fps = static_cast<int>(1 / deltaTime);
    fps.setString(std::to_string(m_fps));
}

void Overlay::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if (IS_DEBUG)
    {
        target.draw(fps);
    }
    target.draw(score, states);
}