//
// Created by Arno Troch on 22/11/2019.
//

#ifndef SPACEINVADERS_PLAYER_H
#define SPACEINVADERS_PLAYER_H

#include "Entity.h"

namespace entity {
    class Player : public Entity {
    private:
    public:
        explicit Player(const Position &position);


    };
}


#endif //SPACEINVADERS_PLAYER_H
