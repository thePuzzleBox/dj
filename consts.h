

#ifndef SFML_PROJECT_CONSTS_H
#define SFML_PROJECT_CONSTS_H
#include <SFML/Graphics.hpp>
#include <string>
#include <functional>
#include <memory>

/// Window params
static const unsigned WINDOW_WIDTH = 640;
static const unsigned WINDOW_HEIGHT = 900;
static const std::string WINDOW_TITLE = "My Doodle Jump";
static const unsigned ANTIALIASING_LEVEL = 8;
static const unsigned MAX_FPS = 60;

/// Game params
static const float G = 9.8f;
static const float TIME_ACCELERATOR = 10.f;
static const float MOVE_SPEED = 500.f;
static const size_t PLATFORM_COUNT = 18;
static const float DOODLER_SPEED = 60.f;
static const unsigned MAX_PRECISION_COUNT = 16;
static const float DEAD_TIME = 2.f;
static const float SCORE_MULTIPLIER = 0.1f;
static const float COLLISION_TOLERANCE = 2.f;

/// Menu params
static const unsigned BASE_MARGIN = 20;
static const unsigned LOGO_TEXT_SIZE = 75;
static const unsigned SCORE_TEXT_SIZE = 50;
static const unsigned GAME_SCORE_TEXT_SIZE = 35;

/// Debug params
extern bool IS_DEBUG;

namespace consts {

//main-system
    constexpr int WIN_WIDTH = 400, WIN_HEIGHT = 640;
    constexpr char WIN_NAME[] = "Doodle Jump";
    constexpr char FONT[] = "assets/MSComicSans.ttf";
    constexpr char ICON[] = "assets/icon.png";

//InputManager
    constexpr char RIGHT = 'd';
    constexpr char LEFT = 'a';
    constexpr char PAUSE = 'p';

//MenuScene
    constexpr char MENU_COVER[] = "assets/covers/menu-cover.png";

//GameScene
    constexpr char SEQ_FILE[] = "assets/sequence.txt";
    constexpr char BACKGROUND_COVER[] = "assets/covers/background.png";
    constexpr char TOPBAR_IMG[] = "assets/top-score.png";
    constexpr char PAUSE_BTN_IMG[] = "assets/pause.png";

//PauseScene
    constexpr char PAUSE_COVER[] = "assets/covers/pause-cover.png";

//GameoverScene
    constexpr char GAMEOVER_COVER[] = "assets/covers/gameover-cover.png";

//Doodle
    constexpr float DOODLE_VY = 0.7f; // pixels per miliseconds
    constexpr float DOODLE_VY_SPRING = 1.3f;
    constexpr float DOODLE_VX = 0.42f;
    constexpr float G = 14 / 10000.0f;

} // namespace consts
#endif //SFML_PROJECT_CONSTS_H
