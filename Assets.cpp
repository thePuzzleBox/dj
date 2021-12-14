
#include "Assets.h"
#include "incbin.h"

INCBIN(ICON_BIN, "res/assets/ui/icon.png");
INCBIN(FONT_BIN, "arial.ttf");
INCBIN(BACKGROUND_BIN, "res/background.png");
INCBIN(DOODLER_BIN, "res/assets/skins/default_R.png");
INCBIN(PLATFORM_BIN, "res/platform.png");
INCBIN(PLAY_BUTTON_BIN, "res/assets/ui/play-button.png");
INCBIN(RESTART_BUTTON_BIN, "res/assets/ui/play-again-button.png");
INCBIN(CANCEL_BUTTON_BIN, "res/assets/ui/cancel-button.png");

BinaryData Assets::ICON = BinaryData{static_cast<size_t>(gICON_BINSize), gICON_BINData};

BinaryData Assets::FONT = BinaryData{static_cast<size_t>(gFONT_BINSize), gFONT_BINData};

BinaryData Assets::BACKGROUND = BinaryData{static_cast<size_t>(gBACKGROUND_BINSize), gBACKGROUND_BINData};

BinaryData Assets::DOODLER = BinaryData{static_cast<size_t>(gDOODLER_BINSize), gDOODLER_BINData};

BinaryData Assets::PLATFORM = BinaryData{static_cast<size_t>(gPLATFORM_BINSize), gPLATFORM_BINData};

BinaryData Assets::PLAY_BUTTON = BinaryData{static_cast<size_t>(gPLAY_BUTTON_BINSize), gPLAY_BUTTON_BINData};

BinaryData Assets::RESTART_BUTTON = BinaryData{static_cast<size_t>(gRESTART_BUTTON_BINSize), gRESTART_BUTTON_BINData};

BinaryData Assets::CANCEL_BUTTON = BinaryData{static_cast<size_t>(gCANCEL_BUTTON_BINSize), gCANCEL_BUTTON_BINData};
