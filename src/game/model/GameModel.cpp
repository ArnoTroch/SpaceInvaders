//
// Created by Arno Troch on 22/11/2019.
//

#include "GameModel.h"
#include "../../entity/Player.h"
#include "../../entity/Invader.h"

// ----------------//
// private methods
// ----------------//
void GameModel::_updatePlayer(double dt) {
    player->move(dt);
    // update player bullet
    if (auto pbullet = player->getBullet().lock()) {
        if (pbullet->isPossibleMove(dt)) {
            // check if move is possible, then move bullet
            pbullet->move(dt);
        } else {
            // if move not possible, remove bullet
            player->removeBullet();
        }
        //TODO add collision detection
    }
}

void GameModel::_updateInvaders(double dt) {
    for (entity::Invader::Ptr &inv: invaders) {
        inv->move(dt);
        // update invader bullet
        if (auto ibullet = inv->getBullet().lock()) {
            if (ibullet->isPossibleMove(dt)) {
                // check if move is possible, then move bullet
                ibullet->move(dt);
            } else {
                // if move not possible, remove bullet
                inv->removeBullet();
            }
            //TODO add collision detection
        }
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

void GameModel::setPlayerBullet() {
    player->shoot();
}

void GameModel::startGame() {
    player = std::make_shared<entity::Player>(); // make player
    for (int i = 0; i < 11; i++) { // make invaders
        invaders.push_back(std::make_shared<entity::Invader>(entity::Position(-3.8 + (0.5 * i), 2.8)));
        invaders.push_back(std::make_shared<entity::Invader>(entity::Position(-3.8 + (0.5 * i), 2.4)));
        invaders.push_back(std::make_shared<entity::Invader>(entity::Position(-3.8 + (0.5 * i), 2.0)));
        invaders.push_back(std::make_shared<entity::Invader>(entity::Position(-3.8 + (0.5 * i), 1.6)));
    }
}

void GameModel::update(double dt) {
    _updatePlayer(dt);
    _updateInvaders(dt);
    notify();
}
