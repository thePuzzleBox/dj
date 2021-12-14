//
// Created by Jalen on 12/9/2021.
//

#ifndef SFML_PROJECT_SKIN_H
#define SFML_PROJECT_SKIN_H
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

class Skin {

public:
    Texture t1, t2;
    string path;

    Skin();
    Skin(int n);
    Skin(string path);
    string getPath(int n);

};


#endif //SFML_PROJECT_SKIN_H
