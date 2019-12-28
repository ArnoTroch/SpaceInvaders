//
// Created by Arno Troch on 23/11/2019.
//

#ifndef SPACEINVADERS_INVADER_H
#define SPACEINVADERS_INVADER_H

#include "Bullet.h"

namespace entity {

    /**
     * Class that represents the enemies (invaders) in the game.
     *
     * This class inherits from the Creature class.
     */
    class Invader : public Creature {
    private:
        Bullet::Ptr bullet;

    public:
        /**
         * shared_ptr to Invader is defined as entity::Invader::Ptr, in order to
         * simplify commonly used types.
         */
        using Ptr = std::shared_ptr<Invader>;

        /**
         * create an Invader
         * @param position position of new Invader
         */
        explicit Invader(const Position &position);

        /**
         * default destructor
         */
        ~Invader() override = default;

        /**
         * get Bullet fired by Invader
         * @return Bullet fired by Invader
         */
        [[nodiscard]] std::weak_ptr<Bullet> getBullet() const;


        /**
         * shoot Bullet if Invader doesn't have an active Bullet yet, or return the active Bullet.
         */
        void shoot();

        /**
         * remove Bullet fired by Invader
         */
        void removeBullet();

        /**
         * get relative path to resources
         * @return relative path to resources for Invader
         */
        std::string getResourcePath() override;

    };

}


#endif //SPACEINVADERS_INVADER_H
