//
// Created by Arno Troch on 18/11/2019.
//

#ifndef SPACEINVADERS_GAME_H
#define SPACEINVADERS_GAME_H

#include "GameView.h"

#define RESOURCES_DIR std::string("../resources/") // relative path to where resources are stored.

/**
 * Main class that combines the different parts of the game.
 *
 *
 */
class Game {
private:
    GameView view;
    sf::Texture texture;    // test for drawing
    sf::Sprite sprite;      // test for drawing
public:
    Game();

    /**
     * run the whole game
     */
    void run();

    /**
     * update different parts of the game
     */
    void update();

    /**
     * draw different parts of the game
     */
    void draw();

    /**
     * Tell if game is still running or not
     * @return
     */
    bool isRunning();

};


#endif //SPACEINVADERS_GAME_H
