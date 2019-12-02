//
// Created by Arno Troch on 19/11/2019.
//

#ifndef SPACEINVADERS_GAMEVIEW_H
#define SPACEINVADERS_GAMEVIEW_H

#include "Observer.h"
#include "../model/GameModel.h"
#include <SFML/Graphics.hpp>

/**
 * Class used to graphically represent the current state of the game.
 *
 * The GameView class represents the current state of a certain GameModel object using the
 * SFML library. It draws all the entities from the model on the screen.
 * The GameView class inherits from the Observer class, as it has to observe the GameModel
 * it is representing.
 */
class GameView : public Observer {
private:
    GameModel::Ptr model;

    sf::RenderWindow window;

public:
    typedef std::shared_ptr<GameView> Ptr;

    /// constructor initialises a GameView with given GameModel object
    explicit GameView(GameModel::Ptr model);

    /// default destructor
    ~GameView() override = default;

    /// get SFML window
    sf::RenderWindow &getWindow();

    /// render the current state of the observed GameModel object
    void render();

    /// call necessary methods to change the game view when notified by GameModel
    void onNotify() override;

};


#endif //SPACEINVADERS_GAMEVIEW_H
