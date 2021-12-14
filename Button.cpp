
#include <SFML/Graphics/Sprite.hpp>
#include "Button.h"

Button::Button(){}

Button::Button(string img, string hover, float x, float y)
{
    t.loadFromFile(img);
    t2.loadFromFile(hover);
    sprite.setTexture(t);
    sprite.setPosition(x, y);
}

void Button::draw(RenderTarget& window, RenderStates states) const
{
    window.draw(sprite);
}

void Button::update()
{
    if(isEnabled(HOVERED) || isEnabled(CLICKED))
        sprite.setTexture(t2);
    else
        sprite.setTexture(t);

}

void Button::eventHandler(RenderWindow& window, Event event)
{
    Vector2f mpos = (Vector2f) Mouse::getPosition(window);

    if(sprite.getGlobalBounds().contains(mpos) && Mouse::isButtonPressed(Mouse::Left))
        enableState(CLICKED);
    else if(sprite.getGlobalBounds().contains(mpos))
        enableState(HOVERED);
    else
    {
        disableState(HOVERED);
        enableState(NEUTRAL);
    }

}