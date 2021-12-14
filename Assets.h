
#ifndef SFML_PROJECT_ASSETS_H
#define SFML_PROJECT_ASSETS_H

#include <SFML/Graphics.hpp>

static const sf::Vector2u ICON_IMAGE_SIZE = {64, 64};
static const sf::Vector2f BACKGROUND_SPRITE_SIZE = {600.f, 800.f};
static const sf::Vector2f DOODLER_SPRITE_SIZE = {50.f, 45.f};
static const sf::Vector2f PLATFORM_SPRITE_SIZE = {40.f, 12.5f};
static const sf::Vector2f BUTTON_SPRITE_SIZE = {220.f, 80.f};

struct BinaryData
{
    size_t length;
    const unsigned char *data;
};

struct Assets
{
    Assets() = delete;

    static BinaryData ICON;
    static BinaryData FONT;
    static BinaryData BACKGROUND;
    static BinaryData DOODLER;
    static BinaryData PLATFORM;
    static BinaryData PLAY_BUTTON;
    static BinaryData RESTART_BUTTON;
    static BinaryData CANCEL_BUTTON;
};

#endif //SFML_PROJECT_ASSETS_H
