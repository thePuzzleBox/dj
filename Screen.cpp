

#include "Screen.h"

Screen::Screen(){}


Screen::Screen(string background)
{
    t.loadFromFile(background);
    sprite.setTexture(t);
}


void Screen::draw(RenderTarget& window, RenderStates states) const
{
    window.draw((sprite));
}