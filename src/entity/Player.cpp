//
// Created by Arno Troch on 22/11/2019.
//

#include "Player.h"


std::string entity::Player::getResourcePath() {
    return RESOURCES_DIR + "player.png";
}

entity::Player::Player(const Position &position) : Creature(position, 100) {}

