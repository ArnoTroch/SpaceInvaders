//
// Created by Arno Troch on 18/11/2019.
//

#include "Entity.h"

#include <utility>

std::string entity::getResourcesDir() {
    return "../resources/";
}

entity::Entity::Entity(entity::Position position, entity::Dimension dimension, int health) :
        position(std::move(position)), dimension(std::move(dimension)), health(health) {}


const entity::Position &entity::Entity::getPosition() const {
    return position;
}

void entity::Entity::setPosition(const entity::Position &pos) {
    Entity::position = pos;
}

const entity::Dimension &entity::Entity::getDimension() const {
    return dimension;
}

int entity::Entity::getHealth() const {
    return health;
}

void entity::Entity::hit() {
    if (health > 0) {
        --health;
    }
}

bool entity::Entity::alive() {
    return health != 0;
}
