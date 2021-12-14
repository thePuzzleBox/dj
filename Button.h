
#ifndef SFML_PROJECT_BUTTON_H
#define SFML_PROJECT_BUTTON_H
#include <string>
#include "States.h"

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Button : public Drawable, public States
{

private:
    Texture t, t2;
    Sprite sprite;

public:
    Button();
    Button(string img, string hover, float x, float y);
    virtual void draw(RenderTarget& window, RenderStates states) const;
    void eventHandler(RenderWindow& window, Event event);
    void update();
};

#endif //SFML_PROJECT_BUTTON_H
