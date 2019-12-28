//
// Created by Arno Troch on 22/11/2019.
//

#ifndef SPACEINVADERS_PLAYER_H
#define SPACEINVADERS_PLAYER_H

#include "Bullet.h"

namespace entity {

    /**
     * Class that represents the player in the game.
     *
     * This class inherits from the Creature class.
     */
    class Player : public Creature {
    private:
        Bullet::Ptr bullet;

    public:
        /**
         * shared_ptr to Player is defined as entity::Player::Ptr, in order to
         * simplify commonly used types.
         */
        using Ptr = std::shared_ptr<Player>;

        /**
         * create a Player
         */
        Player();

        /**
         * default destructor
         */
        ~Player() override = default;

        /**
         * get Bullet fired by Player
         * @return Bullet fired by Player
         */
        [[nodiscard]] std::weak_ptr<Bullet> getBullet() const;

        /**
         * shoot Bullet if Player doesn't have an active Bullet yet, or return the active Bullet.
         */
        void shoot();

        /**
         * remove Bullet fired by Player
         */
        void removeBullet();

        /**
         * get relative path to resources
         * @return relative path to resources for Player
         */
        std::string getResourcePath() override;
    };
}


#endif //SPACEINVADERS_PLAYER_H
