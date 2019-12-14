//
// Created by Arno Troch on 22/11/2019.
//

#include "GameModel.h"
#include "../../entity/Player.h"
#include "../../entity/Invader.h"

// ----------------//
// private methods
// ----------------//
void GameModel::_movePlayer(double dt) {
    entity::Position new_pos;
    switch (player->getDirection()) {
        case entity::MovingDirection::LEFT:
            new_pos = entity::Position(player->getPosition().first - (player->getVelocity() * dt),
                                       player->getPosition().second);
            player->setPosition(new_pos);
            break;
        case entity::MovingDirection::RIGHT:
            new_pos = entity::Position(player->getPosition().first + (player->getVelocity() * dt),
                                       player->getPosition().second);
            player->setPosition(new_pos);
            break;
        default:
            break;
    }
}

void GameModel::_moveInvaders(double dt) {
    for (entity::Invader::Ptr &inv: invaders) {
        if ((inv->getDirection() == entity::MovingDirection::LEFT && inv->getPosition().first > 200) ||
            inv->getPosition().first > 800) {
            // move invader left
            inv->setDirection(entity::MovingDirection::LEFT);
            inv->setPosition(entity::Position(inv->getPosition().first - (inv->getVelocity() * dt),
                                              inv->getPosition().second));
        } else if ((inv->getDirection() == entity::MovingDirection::RIGHT && inv->getPosition().first < 800) ||
                   inv->getPosition().first < 200) {
            // move invader right
            inv->setDirection(entity::MovingDirection::RIGHT);
            inv->setPosition(entity::Position(inv->getPosition().first + (inv->getVelocity() * dt),
                                              inv->getPosition().second));
        }
    }
}

// ----------------//
// public methods
// ----------------//
GameModel::GameModel() {
    player = std::make_shared<entity::Player>(entity::Position(600, 700));
    invaders.push_back(std::make_shared<entity::Invader>(entity::Position(400, 400)));
}

void GameModel::setPlayerDirection(entity::MovingDirection movingDirection) {
    player->setDirection(movingDirection);
}

void GameModel::update(double dt) {
    _movePlayer(dt);
    _moveInvaders(dt);
    notify();
}

const entity::Player::Ptr &GameModel::getPlayer() const {
    return player;
}

const std::vector<entity::Invader::Ptr> &GameModel::getInvaders() const {
    return invaders;
}

