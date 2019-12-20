//
// Created by Arno Troch on 23/11/2019.
//

#include "Invader.h"

entity::Invader::Invader(const Position &position) : Creature(position, {0.4, 0.3}, 0.5) {
    setMovingDirection(MovingDirection::RIGHT);
}

std::string entity::Invader::getResourcePath() {
    return RESOURCES_DIR + "invader.png";
}

