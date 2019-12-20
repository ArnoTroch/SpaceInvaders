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
    private:

    public:
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
         * get relative path to resources
         * @return relative path to resources for Invader
         */
        std::string getResourcePath() override;

    };

}


#endif //SPACEINVADERS_INVADER_H
