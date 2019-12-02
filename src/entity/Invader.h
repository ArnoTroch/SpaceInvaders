//
// Created by Arno Troch on 23/11/2019.
//

#ifndef SPACEINVADERS_INVADER_H
#define SPACEINVADERS_INVADER_H

#include "Creature.h"

namespace entity {

    /**
     * enum class to keep track of Invaders' current moving orientation
     */
    enum class InvaderMovingDirection {
        left,
        right
    };

    /**
     * Class that represents the enemies (invaders) in the game.
     *
     * This class inherits from the Creature class.
     */
    class Invader : public Creature {
    private:
        InvaderMovingDirection moving_dir;

    public:
        typedef std::shared_ptr<Invader> Ptr;

        /// constructor initialises an Invader with given position
        explicit Invader(const Position &position);

        /// default destructor
        ~Invader() override = default;

        /// get direction Invader is moving in
        InvaderMovingDirection getMovingDirection() const;

        /// set new moving direction for Invader
        void setMovingDirection(InvaderMovingDirection movingDir);

        /// get relative path to resources for Invader
        std::string getResourcePath() override;

    };

}


#endif //SPACEINVADERS_INVADER_H
