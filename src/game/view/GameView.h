//
// Created by Arno Troch on 19/11/2019.
//

#ifndef SPACEINVADERS_GAMEVIEW_H
#define SPACEINVADERS_GAMEVIEW_H

#include <SFML/Graphics.hpp>

class GameView {
private:
    sf::RenderWindow window;

public:
    GameView();

    void update();

    void draw(const sf::Drawable &drawable);

    void clear();

    void display();

};


#endif //SPACEINVADERS_GAMEVIEW_H
