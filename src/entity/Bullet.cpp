//
// Created by Arno Troch on 20/12/2019.
//

#include "Bullet.h"

entity::Bullet::Bullet(const entity::Position &position, MovingDirection direction)
        : Creature(position, {0.05, 0.1}, 4) {
    if (direction == MovingDirection::UP || direction == MovingDirection::DOWN) {
        setMovingDirection(direction);
    } // TODO exception handling
}

std::string entity::Bullet::getResourcePath() {
    return RESOURCES_DIR + "bullet.png";
}
