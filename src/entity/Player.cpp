//
// Created by Arno Troch on 22/11/2019.
//

#include "Player.h"

entity::Player::Player() : Creature({0, 0}, {0.4, 0.3}, 2.5), bullet(nullptr) {
    setPosition({0, -3 + (getDimension().second / 2)});
}

std::weak_ptr<entity::Bullet> entity::Player::getBullet() const {
    return bullet;
}

void entity::Player::shoot() {
    if (bullet == nullptr) {
        bullet = std::make_shared<Bullet>(getPosition(), MovingDirection::UP);
        bullet->setPosition({getPosition().first,
                             getPosition().second + ((getDimension().second + bullet->getDimension().second) / 2)});
    }
}

void entity::Player::removeBullet() {
    bullet.reset();
}

std::string entity::Player::getResourcePath() {
    return RESOURCES_DIR + "player.png";
}

