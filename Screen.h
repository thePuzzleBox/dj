
#ifndef SFML_PROJECT_SCREEN_H
#define SFML_PROJECT_SCREEN_H
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Button.h"
#include <string>

using namespace sf;
using namespace std;

class Screen : public Drawable{

    Texture t;
    Sprite sprite;

public:
    Screen();
    Screen(string background);
    virtual void draw(RenderTarget& window, RenderStates states) const;
};


#endif //SFML_PROJECT_SCREEN_H
