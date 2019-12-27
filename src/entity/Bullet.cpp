//
// Created by Arno Troch on 20/12/2019.
//

#include "Bullet.h"

entity::Bullet::Bullet(const entity::Position &position, MovingDirection direction)
        : Creature(position, {0.05, 0.1}, 1, 3) {
    if (direction == MovingDirection::UP || direction == MovingDirection::DOWN) {
        setMovingDirection(direction);
    } // TODO exception handling
}

std::string entity::Bullet::getResourcePath() {
    return entity::getResourcesDir() + "entities/bullet.png";
}
