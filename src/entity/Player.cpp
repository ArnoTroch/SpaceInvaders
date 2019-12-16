//
// Created by Arno Troch on 22/11/2019.
//

#include "Player.h"

entity::Player::Player() : Creature({0, 0}, {0.4, 0.3}, 3) {
    setPosition({0, -3 + (getDimension().second / 2)});
}

std::string entity::Player::getResourcePath() {
    return RESOURCES_DIR + "player.png";
}

