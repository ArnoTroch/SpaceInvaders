//
// Created by Arno Troch on 23/11/2019.
//

#ifndef SPACEINVADERS_CREATURE_H
#define SPACEINVADERS_CREATURE_H

#include "Entity.h"

namespace entity {

    /**
     * Abstract class that represents all living creatures in the game
     */
    class Creature : public Entity {
    private:
        double velocity;

    public:
        typedef std::shared_ptr<Creature> Ptr;

        /**
         * create a Creature
         * @param position position of creature
         * @param velocity velocity of creature
         */
        Creature(const Position &position, double velocity);

        /// default destructor
        ~Creature() override = default;

        /// get velocity
        double getVelocity() const;

        /// set new velocity
        void setVelocity(double velocity);


    };

}

#endif //SPACEINVADERS_CREATURE_H
