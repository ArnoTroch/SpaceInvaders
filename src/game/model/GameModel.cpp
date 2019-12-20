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
    player->move(dt);
}

void GameModel::_moveInvaders(double dt) {
    for (entity::Invader::Ptr &inv: invaders) {
        inv->move(dt);
    }
}

// ----------------//
// public methods
// ----------------//
GameModel::GameModel() {
    startGame();
}

const entity::Player::Ptr &GameModel::getPlayer() const {
    return player;
}

const std::vector<entity::Invader::Ptr> &GameModel::getInvaders() const {
    return invaders;
}

void GameModel::setPlayerDirection(entity::MovingDirection movingDirection) {
    player->setMovingDirection(movingDirection);
}

void GameModel::setInvaderDirection(entity::MovingDirection movingDirection) {
    for (entity::Invader::Ptr &inv: invaders) {
        inv->setMovingDirection(movingDirection);
    }
}


void GameModel::startGame() {
    player = std::make_shared<entity::Player>(); // make player
    for (int i = 0; i < 11; i++) { // make invaders
        invaders.push_back(std::make_shared<entity::Invader>(entity::Position(-3.8 + (0.5 * i), 2.8)));
        invaders.push_back(std::make_shared<entity::Invader>(entity::Position(-3.8 + (0.5 * i), 2.4)));
        invaders.push_back(std::make_shared<entity::Invader>(entity::Position(-3.8 + (0.5 * i), 2.0)));
        invaders.push_back(std::make_shared<entity::Invader>(entity::Position(-3.8 + (0.5 * i), 1.6)));
        //invaders.push_back(std::make_shared<entity::Invader>(entity::Position(-3.8 + (0.5 * i), 1.2)));
    }
}

void GameModel::update(double dt) {
    _movePlayer(dt);
    _moveInvaders(dt);
    notify();
}
