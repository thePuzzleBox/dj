

#ifndef SFML_PROJECT_SCORE_H
#define SFML_PROJECT_SCORE_H

#pragma once

#include <iostream>
using namespace std;

namespace Score {
    void Save(const string &path, size_t score);
    size_t Load(const string &path);
}

#endif //SFML_PROJECT_SCORE_H
