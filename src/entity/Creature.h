//
// Created by Arno Troch on 23/11/2019.
//

#ifndef SPACEINVADERS_CREATURE_H
#define SPACEINVADERS_CREATURE_H

#include "Entity.h"

namespace entity {

    /**
     * enum class to keep track of entity's current moving direction.
     */
    enum class MovingDirection {
        LEFT,
        RIGHT,
        UP,
        DOWN,
        IDLE
    };

    /**
     * Abstract class that represents all living creatures in the game
     */
    class Creature : public Entity {
    private:
        double velocity;

        MovingDirection direction;

    public:
        using Ptr = std::shared_ptr<Creature>;

        /**
         * create a Creature
         * @param position position of creature
         * @param velocity velocity of creature
         */
        Creature(const Position &position, double velocity);

        /// default destructor
        ~Creature() override = default;

        /// get velocity
        [[nodiscard]] double getVelocity() const;

        /// set new velocity
        void setVelocity(double velocity);

        [[nodiscard]] MovingDirection getDirection() const;

        void setDirection(MovingDirection direction);

    };

}

#endif //SPACEINVADERS_CREATURE_H
