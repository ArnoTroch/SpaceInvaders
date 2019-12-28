//
// Created by Arno Troch on 20/12/2019.
//

#ifndef SPACEINVADERS_BULLET_H
#define SPACEINVADERS_BULLET_H

#include "Creature.h"

namespace entity {

    /**
     * Class that represents the bullets being fired from the Invader and Player objects.
     *
     * The Bullet class inherits from the Creature class. Although it isn't an actual 'creature', it moves and needs
     * a velocity because of that, just like the other creatures.
     */
    class Bullet : public Creature {
    private:

    public:
        /**
         * shared_ptr to Bullet is defined as entity::Bullet::Ptr, in order to
         * simplify commonly used types.
         */
        using Ptr = std::shared_ptr<Bullet>;

        /**
         * weak_ptr to a Bullet is defined as entity::Bullet::wPtr, in order to simplify commonly used types.
         */
        using wPtr = std::weak_ptr<Bullet>;

        /**
         * create a Bullet
         * @param position position of new Bullet
         * @param direction moving direction of new Bullet. This can only be entity::MovingDirection::UP or
         * entity::MovingDirection::DOWN
         */
        explicit Bullet(const Position &position, MovingDirection direction);

        /**
         * default destructor
         */
        ~Bullet() override = default;

        /**
         * get relative path to resources
         * @return relative path to resources for Bullet
         */
        std::string getResourcePath() override;
    };
}


#endif //SPACEINVADERS_BULLET_H
