//
// Created by Arno Troch on 22/11/2019.
//

#ifndef SPACEINVADERS_GAMEMODEL_H
#define SPACEINVADERS_GAMEMODEL_H

#include "Subject.h"
#include "../../entity/Player.h"
#include "../../entity/Invader.h"
#include "../../entity/Bullet.h"
#include "../../entity/Shield.h"

namespace game {
    /**
     * Class containing all the game data.
     *
     * The GameModel class is a part of the MVC design pattern. It is used as the 'database' of the game.
     * It contains all the entities and performs modifications to them, like changing their position, health,
     * etc. The dimensions of the game model world are [-4,4] x [-3,3], so the game model will know nothing about
     * the actual pixel resolution of the screen. The conversion from this coordinate systems to the pixel values
     * will be done by the Transformation class.
     * The GameModel class inherits from the Subject class, as it has to be observed by a GameView object.
     */
    class GameModel : public Subject {
    public:
        /**
         * Enum for keeping track of GameModel state.
         *
         * The state of the game will decide which input the GameController should check, how the GameModel
         * changes and what the GameView will display.
         */
        enum class State {
            INITIALIZING,
            TITLE_SCREEN,
            GAME_RUNNING,
            WAVE_OVER,
            GAME_OVER
        };

    private:
        entity::Player::Ptr player; // player

        std::vector<entity::Invader::Ptr> invaders; // enemies

        std::vector<entity::Shield::Ptr> shields; // shields

        int currentLevel; // current game level

        State state; // game state

        void _updatePlayer(double dt);

        void _updateInvaders(double dt);

        void _updateShields();

        static bool _entityCollision(const entity::Entity::Ptr &e1, const entity::Entity::Ptr &e2);

        friend class GameController;

    public:
        /**
         * shared_ptr to GameModel is defined as game::GameModel::Ptr, in order to
         * simplify commonly used types.
         */
        using Ptr = std::shared_ptr<GameModel>;

        /**
         * create a GameModel
         */
        GameModel();

        /**
         * default destructor
         */
        virtual ~GameModel() = default;

        /**
         * get player
         * @return player of GameModel
         */
        [[nodiscard]] const entity::Player::Ptr &getPlayer() const;

        /**
         * get invaders
         * @return invaders of GameModel
         */
        [[nodiscard]] const std::vector<entity::Invader::Ptr> &getInvaders() const;

        /**
         * get shields
         * @return shields of GameModel
         */
        [[nodiscard]] const std::vector<entity::Shield::Ptr> &getShields() const;

        /**
         * get current level
         * @return current level of GameModel
         */
        [[nodiscard]] int getCurrentLevel() const;

        /**
         * get game state
         * @return game state of GameModel
         */
        [[nodiscard]] State getState() const;

        /**
         * set game state
         * @param state new game state of GameModel
         */
        void setState(State state);

        /**
         * set new moving direction for player
         * @param movingDirection new moving direction for player
         */
        void setPlayerDirection(entity::MovingDirection movingDirection);

        /**
         * set new moving direction for all invaders
         * @param movingDirection new moving direction for all invaders
         */
        void setInvaderDirection(entity::MovingDirection movingDirection);

        /**
         * create all necessary entities to start a new level
         */
        void setup();

        /**
         * update the game model
         * @param dt delta time
         */
        void update(double dt);
    };
}


#endif //SPACEINVADERS_GAMEMODEL_H
