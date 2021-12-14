
#ifndef SFML_PROJECT_ENUMS_H
#define SFML_PROJECT_ENUMS_H
#include <cstdlib>

enum class EState : size_t
{
    MAIN_MENU = 0,
    PAUSE_MENU,
    GAME_OVER,
    GAME_PROCESS
};

enum class EType : size_t
{
    PLATFORM_DEFAULT = 0,
    PLATFORM_BONUS_SPRING,
    PLATFORM_BONUS_TRAMPOLINE,
    DOODLER,
    SPRITE
};

#endif //SFML_PROJECT_ENUMS_H
