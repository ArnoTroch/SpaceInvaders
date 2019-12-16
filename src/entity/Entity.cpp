//
// Created by Arno Troch on 18/11/2019.
//

#include "Entity.h"

#include <utility>

entity::Entity::Entity(entity::Position position, entity::Dimension dimension) : position(std::move(position)),
                                                                                 dimension(std::move(dimension)) {}


const entity::Position &entity::Entity::getPosition() const {
    return position;
}

void entity::Entity::setPosition(const entity::Position &pos) {
    Entity::position = pos;
}

const entity::Dimension &entity::Entity::getDimension() const {
    return dimension;
}

