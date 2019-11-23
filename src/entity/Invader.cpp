//
// Created by Arno Troch on 23/11/2019.
//

#include "Invader.h"

entity::Invader::Invader(const Position &position) :
        Creature(position, 200),
        moving_dir(InvaderMovingDirection::right) {}

std::string entity::Invader::getResourcePath() {
    return RESOURCES_DIR + "invader.png";
}

entity::InvaderMovingDirection entity::Invader::getMovingDirection() const {
    return moving_dir;
}

void entity::Invader::setMovingDirection(entity::InvaderMovingDirection moving_direction) {
    moving_dir = moving_direction;
}
