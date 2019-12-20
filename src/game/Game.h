//
// Created by Arno Troch on 18/11/2019.
//

#ifndef SPACEINVADERS_GAME_H
#define SPACEINVADERS_GAME_H

#include "view/GameView.h"
#include "model/GameModel.h"
#include "controller/GameController.h"
#include "Stopwatch.h"
#include <iostream>

#define RESOURCES_DIR std::string("../resources/") // relative path to where resources are stored.

/**
 * Main class that combines the different parts of the game.
 *
 * The Game class contains the game model, view and controller, which are constructed when calling the
 * Game constructor.
 */
class Game {
private:
    GameView::Ptr view;

    GameModel::Ptr model;

    GameController::Ptr controller;

    double dt;

    void _update();

    void _updateDt();

public:
    /**
     * create a Game
     */
    Game();

    /**
     * run the game
     */
    void run();

};


#endif //SPACEINVADERS_GAME_H
