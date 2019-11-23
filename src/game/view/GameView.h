//
// Created by Arno Troch on 19/11/2019.
//

#ifndef SPACEINVADERS_GAMEVIEW_H
#define SPACEINVADERS_GAMEVIEW_H

#include "Observer.h"
#include "../model/GameModel.h"
#include <SFML/Graphics.hpp>

class GameView : public Observer {
private:
    GameModel::Ptr model;

    sf::RenderWindow window;

public:
    typedef std::shared_ptr<GameView> Ptr;

    explicit GameView(GameModel::Ptr model);

    ~GameView() override = default;

    sf::RenderWindow &getWindow();

    void render();

    void onNotify() override;

};


#endif //SPACEINVADERS_GAMEVIEW_H
