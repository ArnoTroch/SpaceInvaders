//
// Created by Arno Troch on 23/11/2019.
//

#ifndef SPACEINVADERS_GAMECONTROLLER_H
#define SPACEINVADERS_GAMECONTROLLER_H

#include "../model/GameModel.h"
#include "../utils/Settings.h"
#include <random>

namespace game {
    /**
     * Class that handles input and updates the game model.
     *
     * The GameController class is a part of the MVC design pattern. Its goal is to process the user's
     * keyboard input and tell the GameModel how to change its data (according to the keyboard input).
     */
    class GameController {
    private:
        GameModel::Ptr model; // model being handled by controller

        void _handleTitleScreen();

        void _handleWaveOver();

        void _handlePlayer();

        void _handleInvaders(double dt);

        void _loadLevel();

        utils::Settings settings; // settings

    public:
        /**
         * shared_ptr to GameController is defined as game::GameController::Ptr, in order to
         * simplify commonly used types.
         */
        using Ptr = std::shared_ptr<GameController>;

        /**
         * create a GameController that handles a specific model
         * @param model model to be handled by new GameController
         */
        explicit GameController(GameModel::Ptr model);

        /**
         *  default destructor
         */
        virtual ~GameController() = default;

        /**
         * handle input and update the game model accordingly
         * @param dt delta time
         */
        void update(double dt);

    };
}


#endif //SPACEINVADERS_GAMECONTROLLER_H
