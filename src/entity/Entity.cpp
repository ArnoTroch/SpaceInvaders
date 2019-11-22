//
// Created by Arno Troch on 18/11/2019.
//

#include "Entity.h"

entity::Entity::Entity(const Position &position) : position(position) {}

const Position &entity::Entity::getPosition() const {
    return position;
}

void entity::Entity::setPosition(const Position &pos) {
    Entity::position = pos;
}

