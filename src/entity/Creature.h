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

        double velocityMultiplier;

        MovingDirection direction;

    public:
        /**
         * shared_ptr to Creature is defined as entity::Creature::Ptr, in order to
         * simplify commonly used types.
         */
        using Ptr = std::shared_ptr<Creature>;

        /**
         * create a Creature
         * @param position position of new Creature
         * @param dimension dimension of new Creature
         * @param health health of new Creature
         * @param velocity velocity of new Creature
         * @param velocityMultiplier multiplier of new Creature
         */
        Creature(const Position &position, const Dimension &dimension, int health, double velocity,
                 double velocityMultiplier = 1);

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
         * get velocity multiplier
         * @return velocity multiplier of Creature
         */
        [[nodiscard]] double getVelocityMultiplier() const;

        /**
         * set new velocity multiplier
         * @param velocityMultiplier new velocity multiplier of Creature
         */
        void setVelocityMultiplier(double velocityMultiplier);

        /**
         * get moving direction
         * @return moving direction of Creature
         */
        [[nodiscard]] MovingDirection getMovingDirection() const;

        /**
         * set new moving direction
         * @param movingDirection new moving direction of Creature
         */
        void setMovingDirection(MovingDirection movingDirection);

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
