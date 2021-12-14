
#include "Skin.h"

Skin::Skin(){}

Skin::Skin(int n)
{
    string path = getPath(n);
    (*this).path = path;
    t1.loadFromFile(path + "R.png");
    t2.loadFromFile(path + "L.png");
}

Skin::Skin(string path)
{
    t1.loadFromFile(path + "R.png");
    t2.loadFromFile(path + "L.png");
}

string Skin::getPath(int n)
{
    string str;

    switch(n)
    {
        case 1:
            str = "res/assets/skins/default_"; break;
        case 2:
            str = "res/assets/skins/soccer_"; break;
        case 3:
            str = "res/assets/skins/bunny_"; break;
        case 4:
            str = "res/assets/skins/ninja_"; break;
        case 5:
            str = "res/assets/skins/snow_"; break;
        case 6:
            str = "res/assets/skins/frozen_"; break;
        case 7:
            str = "res/assets/skins/underwater_"; break;
        case 8:
            str = "res/assets/skins/space_";
    }
    return str;
}
