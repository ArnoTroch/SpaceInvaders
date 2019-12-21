//
// Created by Arno Troch on 23/11/2019.
//

#ifndef SPACEINVADERS_CREATURE_H
#define SPACEINVADERS_CREATURE_H

#include "Entity.h"
#include <cmath>

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
     * Abstract class that represents all living and moving creatures in the game
     */
    class Creature : public Entity {
    private:
        double velocity;

        MovingDirection direction;

    public:
        using Ptr = std::shared_ptr<Creature>;

        /**
         * create a Creature
         * @param position position of new Creature
         * @param dimension dimension of new Creature
         * @param velocity velocity of new Creature
         */
        Creature(const Position &position, const Dimension &dimension, double velocity);

        /**
         * default destructor
         */
        ~Creature() override = default;

        /**
         * get velocity
         * @return velocity of Creature
         */
        [[nodiscard]] double getVelocity() const;

        /**
         * get moving direction
         * @return moving direction of Creature
         */
        [[nodiscard]] MovingDirection getMovingDirection() const;

        /**
         * set new moving direction
         * @param direction new moving direction of Creature
         */
        void setMovingDirection(MovingDirection direction);

        /**
         * check if move in current direction with current velocity is possible, i.e. is still
         * in GameModel world boundaries.
         * @param dt delta time
         * @return true if move is possible, false otherwise
         */
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
