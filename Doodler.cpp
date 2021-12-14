
#include "Doodler.h"

Doodler::Doodler(States &stateMediator) : states(stateMediator)
{
    setPosition(position);
}

void Doodler::updatePosition(const float deltaTime)
{
    setHorizontalPosition(MOVE_SPEED, deltaTime);
    updateTimeAccumulators(deltaTime);
    sf::Vector2f nextPosition = {position.x, getNextY()};
    setFallingState(nextPosition.y);
    setPosition(nextPosition);
    checkCollision();
    checkGameOver();
}

void Doodler::checkCollision()
{
    const bool shouldCheck = intersection != WINDOW_HEIGHT * 2;
    if (!shouldCheck || !isFalling)
    {
        return;
    }

    const float lhs = getPosition().y + getSize().y / 2;
    const float rhs = std::abs(std::abs(lhs) - std::abs(intersection));

    const bool isAtFloorLevel = int(lhs) == int(intersection) ||
                                std::ceil(lhs) == std::ceil(intersection) ||
                                std::floor(lhs) == std::floor(intersection) ||
                                (rhs < COLLISION_TOLERANCE && rhs > 0.f);

    if (isAtFloorLevel)
    {
        checkBonus();
        setNextY(intersection);
        resetTimeAccumulators();
    }
}

void Doodler::checkBonus()
{
    if (speed != DOODLER_SPEED)
    {
        speed = DOODLER_SPEED;
    }

    if (bonus == EType::PLATFORM_BONUS_SPRING)
    {
        speed = DOODLER_SPEED * 1.5f;
        bonus = EType::PLATFORM_DEFAULT;
    }

    if (bonus == EType::PLATFORM_BONUS_TRAMPOLINE)
    {
        speed = DOODLER_SPEED * 3;
        bonus = EType::PLATFORM_DEFAULT;
    }
}

void Doodler::setHorizontalPosition(const float nextX, const float deltaTime)
{
    const KeysMap &keysMap = states.getKeysMap();
    const sf::Vector2f &size = getSize();
    const sf::FloatRect bounds = getBoundingCoordinates();
    const bool isMaxRightPosition = bounds.width - size.x / 2 > WINDOW_WIDTH;
    const bool isMaxLeftPosition = bounds.left + size.x / 2 < 0;
    if (keysMap.at(sf::Keyboard::Right))
    {
        if (isMaxRightPosition)
        {
            position.x = 0.f;
        } else
        {
            position.x += nextX * deltaTime;
        }
    } else if (keysMap.at(sf::Keyboard::Left))
    {
        if (isMaxLeftPosition)
        {
            position.x = WINDOW_WIDTH;
        } else
        {
            position.x -= nextX * deltaTime;
        }
    }
}

EType Doodler::getType() const
{
    return EType::DOODLER;
}

const sf::Vector2f &Doodler::getSize() const
{
    return size;
}

void Doodler::setPlatformIntersection(float nextIntersection)
{
    if (!isFalling)
    {
        return;
    }
    intersection = nextIntersection;
}

void Doodler::setFallingState(const float nextY)
{
    isFalling = getPosition().y - nextY <= 0;
}

bool Doodler::getFallingState() const
{
    return isFalling;
}

void Doodler::setNextY(const float nextY)
{
    position.y = nextY - size.y / 2;
}

float Doodler::getNextY() const
{
    const float lhs = speed * jumpTimeAccumulator;
    const auto rhs = static_cast<float>(0.5 * G * std::pow(jumpTimeAccumulator, 2));
    return position.y - lhs + rhs;
}

sf::FloatRect Doodler::getBoundingCoordinates() const
{
    const sf::Vector2f &position = getPosition();
    const float left = position.x - size.x / 2;
    const float width = position.x + size.x / 2;
    const float top = position.y - size.x / 2;
    const float height = position.y + size.y / 2;
    return sf::FloatRect(left, top, width, height);
}

void Doodler::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(spite, states);
}

void Doodler::eventHandler(const sf::Event &event)
{
    if (event.type != sf::Event::KeyPressed)
    {
        return;
    }
    if (event.key.code == sf::Keyboard::Left)
    {
        setScale({-1.f, 1.f});
    } else if (event.key.code == sf::Keyboard::Right)
    {
        setScale({1.f, 1.f});
    }
}

void Doodler::setBonusType(EType nextType)
{
    bonus = nextType;
}

void Doodler::resetTimeAccumulators()
{
    jumpTimeAccumulator = 0.f;
    fallTimeAccumulator = 0.f;
}

void Doodler::checkGameOver()
{
    const bool isOverDeadTime = fallTimeAccumulator / TIME_ACCELERATOR > DEAD_TIME;
    if (isOverDeadTime)
    {
        states.setState(EState::GAME_OVER);
        resetTimeAccumulators();
    }
}

void Doodler::updateTimeAccumulators(const float deltaTime)
{
    jumpTimeAccumulator += deltaTime * TIME_ACCELERATOR;
    if (isFalling)
    {
        fallTimeAccumulator += deltaTime * TIME_ACCELERATOR;
    }
}
