//
// Created by Arno Troch on 23/11/2019.
//

#ifndef SPACEINVADERS_GAMECONTROLLER_H
#define SPACEINVADERS_GAMECONTROLLER_H

#include "../model/GameModel.h"

/**
 * Class that handles input and updates the game model
 */
class GameController {
private:
    GameModel::Ptr model; // model being handled by controller

    void _handlePlayer(double dt);

    void _handleInvaders(double dt);

public:
    typedef std::shared_ptr<GameController> Ptr;

    /**
     * create a GameController that handles a specific model
     * @param model model to be handled by controller
     */
    explicit GameController(GameModel::Ptr model);

    /**
     * default destructor
     */
    virtual ~GameController() = default;

    /**
     * handle input and update the game model accordingly
     * @param dt delta time
     */
    void update(double dt);

};


#endif //SPACEINVADERS_GAMECONTROLLER_H
