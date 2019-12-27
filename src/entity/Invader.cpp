//
// Created by Arno Troch on 23/11/2019.
//

#include "Invader.h"

entity::Invader::Invader(const Position &position) : Creature(position, {0.4, 0.3}, 1, 0.5) {
    setMovingDirection(MovingDirection::RIGHT);
}

std::weak_ptr<entity::Bullet> entity::Invader::getBullet() const {
    return bullet;
}

void entity::Invader::shoot() {
    if (bullet == nullptr) {
        bullet = std::make_shared<Bullet>(getPosition(), MovingDirection::DOWN);
        bullet->setPosition({getPosition().first,
                             getPosition().second - ((getDimension().second + bullet->getDimension().second) / 2)});
    }
}

void entity::Invader::removeBullet() {
    bullet.reset();
}

std::string entity::Invader::getResourcePath() {
    return entity::getResourcesDir() + "entities/invader.png";
}

