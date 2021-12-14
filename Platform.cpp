#include "Platform.h"

float Platform::multiplier = 1.f;

Platform::Platform()
{
    setRandomBonusSprites();

    const float minX = m_size.x / 2;
    const float maxX = WINDOW_WIDTH - m_size.x / 2;
    m_position.x = minX + (rand() % static_cast<int>(maxX - minX + 1));

    const float minY = WINDOW_HEIGHT - multiplier * WINDOW_HEIGHT;
    const float maxY = -multiplier * WINDOW_HEIGHT;
    m_position.y = minY + (rand() % static_cast<int>(maxY - minY + 1));

    setPosition(m_position);
}

void Platform::setRandomBonusSprites()
{
    if (rand() % PLATFORM_COUNT != 0)
    {
        return;
    }
}

EType Platform::getType() const
{
    return m_type;
}

const sf::Vector2f &Platform::getSize() const
{
    return m_size;
}

sf::FloatRect Platform::getBoundingCoordinates() const
{
    const sf::Vector2f &position = getPosition();
    const float left = position.x;
    const float width = position.x + m_size.x;
    const float top = position.y;
    const float height = position.y + m_size.y;
    return sf::FloatRect(left, top, width, height);
}

void Platform::incrementMultiplier()
{
    ++multiplier;
}

void Platform::resetMultiplier()
{
    multiplier = 1.f;
}

void Platform::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(*m_p_sprite, states);
}