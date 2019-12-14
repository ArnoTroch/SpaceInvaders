//
// Created by Arno Troch on 18/11/2019.
//

#include "Entity.h"

#include <utility>

entity::Entity::Entity(entity::Position position) : position(std::move(position)) {}

const entity::Position &entity::Entity::getPosition() const {
    return position;
}

void entity::Entity::setPosition(const entity::Position &pos) {
    Entity::position = pos;
}

