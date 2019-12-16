//
// Created by Arno Troch on 22/11/2019.
//

#ifndef SPACEINVADERS_PLAYER_H
#define SPACEINVADERS_PLAYER_H

#include "Creature.h"

namespace entity {

    /**
     * Class that represents the player in the game.
     *
     * This class inherits from the Creature class.
     */
    class Player : public Creature {
    private:

    public:
        using Ptr = std::shared_ptr<Player>;

        /// default constructor
        Player();

        /// default destructor
        ~Player() override = default;

        /// get relative path to resources for player
        std::string getResourcePath() override;
    };
}


#endif //SPACEINVADERS_PLAYER_H
