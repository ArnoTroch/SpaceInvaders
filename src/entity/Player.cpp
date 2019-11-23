//
// Created by Arno Troch on 22/11/2019.
//

#include "Player.h"

entity::Player::Player(const Position &position) : Creature(position, 500) {}

std::string entity::Player::getResourcePath() {
    return RESOURCES_DIR + "player.png";
}

