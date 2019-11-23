//
// Created by Arno Troch on 23/11/2019.
//

#ifndef SPACEINVADERS_INVADER_H
#define SPACEINVADERS_INVADER_H

#include "Creature.h"

namespace entity {

    /**
     * Class that represents the enemies (invaders) in the game.
     *
     * This class inherits from the Creature class.
     */
    class Invader : public Creature {
    public:
        typedef std::shared_ptr<Invader> Ptr;

        /**
         * create an Invader with given position
         * @param position invader position
         */
        explicit Invader(const Position &position);

        /**
         * default destructor
         */
        ~Invader() override = default;

        /**
         * get relative path to resources for invader
         * @return relative path to invader resources
         */
        std::string getResourcePath() override;

    };

}


#endif //SPACEINVADERS_INVADER_H
