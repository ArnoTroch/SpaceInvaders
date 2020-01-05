//
// Created by Arno Troch on 19/11/2019.
//

#ifndef SPACEINVADERS_GAMEVIEW_H
#define SPACEINVADERS_GAMEVIEW_H

#include "Observer.h"
#include "../model/GameModel.h"
#include "../utils/Transformation.h"
#include "../utils/ResourceLibrary.h"

namespace game {
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

        utils::ResourceLibrary resources;

        // adjust sprite origin, position and scale to fit the RenderWindow
        static void _adjustSprite(sf::Sprite &sprite, const entity::Entity::Ptr &entity);

        void _drawBackground(const std::string &path);

        void _drawSprite(const entity::Entity::Ptr &entity);

        void _renderTitleScreen();

        void _renderGameplay();

        void _renderGameOver();

        void _renderWaveOver();

    public:
        /**
         * shared_ptr to GameView is defined as game::GameView::Ptr, in order to
         * simplify commonly used types.
         */
        using Ptr = std::shared_ptr<GameView>;

        /**
         * create a GameView
         * @param model GameModel being observed by new GameView
         */
        explicit GameView(GameModel::Ptr model);

        /**
         * default destructor
         */
        ~GameView() override = default;

        /**
         * get SFML RenderWindow
         * @return SFML RenderWindow of GameView
         */
        sf::RenderWindow &getWindow();

        /**
         * render the current state of the observed GameModel object
         */
        void render();

        /**
         * call necessary methods to change GameView when notified by GameModel
         */
        void onNotify() override;

    };
}


#endif //SPACEINVADERS_GAMEVIEW_H
