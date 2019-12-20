//
// Created by Arno Troch on 23/11/2019.
//

#ifndef SPACEINVADERS_CREATURE_H
#define SPACEINVADERS_CREATURE_H

#include "Entity.h"
#include <cmath>

namespace entity {

    // maximum value the x and y coordinates of an entity can be
    static const int MAX_X = 4, MAX_Y = 3;

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
         * * create a Creature
         * @param position position of creature
         * @param dimension dimension of creature
         * @param velocity velocity of creature
         */
        Creature(const Position &position, const Dimension &dimension, double velocity);

        /// default destructor
        ~Creature() override = default;

        /// get velocity
        [[nodiscard]] double getVelocity() const;

        /// set new velocity
        void setVelocity(double velocity);

        /// get moving direction
        [[nodiscard]] MovingDirection getMovingDirection() const;

        /// set new moving direction
        void setMovingDirection(MovingDirection direction);

        [[nodiscard]] bool isPossibleMove(double dt) const;

        /**
         * move Creature in current direction with current velocity
         * @param dt delta time
         * @return true if move is in GameModel boundaries, false otherwise
         */
        bool move(double dt);

    };

}

#endif //SPACEINVADERS_CREATURE_H
