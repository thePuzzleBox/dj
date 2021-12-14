

#ifndef SFML_PROJECT_VIEW_H
#define SFML_PROJECT_VIEW_H

#include <SFML/Graphics.hpp>
#include "Doodler.h"

class View
{
public:
    View();

    sf::View &getView();

    void followTo(const std::shared_ptr<IEntity> &p_doodler);

private:
    sf::View m_view;
};

#endif //SFML_PROJECT_VIEW_H
