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
        typedef std::shared_ptr<Player> Ptr;

        /**
         * create a Player with given position
         * @param position player position
         */
        explicit Player(const Position &position);

        /**
         * default destructor
         */
        ~Player() override = default;

        /**
         * get relative path to resources for player
         * @return relative path to player resources
         */
        std::string getResourcePath() override;
    };
}


#endif //SPACEINVADERS_PLAYER_H
