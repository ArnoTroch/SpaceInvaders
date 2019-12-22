//
// Created by Arno Troch on 22/11/2019.
//

#include "GameModel.h"
#include "../../entity/Player.h"
#include "../../entity/Invader.h"

// ----------------//
// private methods
// ----------------//
void game::GameModel::_updatePlayer(double dt) {
    player->move(dt);
    // update player bullet
    if (auto bullet = player->getBullet().lock()) {
        if (bullet->isPossibleMove(dt) && bullet->alive()) {
            // check if move is possible and if bullet didn't hit anything,
            // then move bullet
            bullet->move(dt);
        } else {
            // if move not possible or bullet hit something, remove bullet
            player->removeBullet();
        }
    }
}

void game::GameModel::_updateInvaders(double dt) {
    std::vector<int> invaders_to_delete;
    for (int i = 0; i < invaders.size(); ++i) {
        if (invaders[i]->alive()) {
            invaders[i]->move(dt);
            // update invader bullet
            if (auto bullet = invaders[i]->getBullet().lock()) {
                if (bullet->isPossibleMove(dt) && bullet->alive()) {
                    // check if move is possible and if bullet didn't hit anything,
                    // then move bullet
                    bullet->move(dt);
                } else {
                    // if move not possible or bullet hit something, remove bullet
                    invaders[i]->removeBullet();
                }
            }
        } else {
            // if invader is dead, add index to invaders_to_delete
            invaders_to_delete.push_back(i);
        }
    }
    for (int k: invaders_to_delete) {
        invaders.erase(invaders.begin() + k);
    }
}

void game::GameModel::_checkPlayerCollision() {
    // top left and bottom right player coordinate
    entity::Position tl1 = {player->getPosition().first - (player->getDimension().first / 2),
                            player->getPosition().second + (player->getDimension().second / 2)};
    entity::Position br1 = {player->getPosition().first + (player->getDimension().first / 2),
                            player->getPosition().second - (player->getDimension().second / 2)};
    // check if player was hit by bullet or invader
    for (entity::Invader::Ptr &inv: invaders) {
        if (auto bullet = inv->getBullet().lock()) {
            // top left and bottom right bullet coordinate
            entity::Position tl2 = {bullet->getPosition().first - (bullet->getDimension().first / 2),
                                    bullet->getPosition().second + (bullet->getDimension().second / 2)};
            entity::Position br2 = {bullet->getPosition().first + (bullet->getDimension().first / 2),
                                    bullet->getPosition().second - (bullet->getDimension().second / 2)};
            // check if invader position overlaps with player bullet
            if (tl1.first < br2.first && tl2.first < br1.first && br2.second < tl1.second && br1.second < tl2.second) {
                player->hit();
                bullet->hit();
            }
        }
    }
}

void game::GameModel::_checkInvaderCollision() {
    // check if invader was hit by bullet
    if (auto bullet = player->getBullet().lock()) {
        // top left and bottom right bullet coordinate
        entity::Position tl1 = {bullet->getPosition().first - (bullet->getDimension().first / 2),
                                bullet->getPosition().second + (bullet->getDimension().second / 2)};
        entity::Position br1 = {bullet->getPosition().first + (bullet->getDimension().first / 2),
                                bullet->getPosition().second - (bullet->getDimension().second / 2)};
        for (entity::Invader::Ptr &inv: invaders) {
            // top left and bottom right invader coordinate
            entity::Position tl2 = {inv->getPosition().first - (inv->getDimension().first / 2),
                                    inv->getPosition().second + (inv->getDimension().second / 2)};
            entity::Position br2 = {inv->getPosition().first + (inv->getDimension().first / 2),
                                    inv->getPosition().second - (inv->getDimension().second / 2)};
            // check if invader position overlaps with player bullet
            if (tl1.first < br2.first && tl2.first < br1.first && br2.second < tl1.second && br1.second < tl2.second) {
                inv->hit();
                bullet->hit();
            }
        }
    }
}


// ----------------//
// public methods
// ----------------//
game::GameModel::GameModel() {
    startGame();
}

const entity::Player::Ptr &game::GameModel::getPlayer() const {
    return player;
}

const std::vector<entity::Invader::Ptr> &game::GameModel::getInvaders() const {
    return invaders;
}

void game::GameModel::setPlayerDirection(entity::MovingDirection movingDirection) {
    player->setMovingDirection(movingDirection);
}

void game::GameModel::setInvaderDirection(entity::MovingDirection movingDirection) {
    for (entity::Invader::Ptr &inv: invaders) {
        inv->setMovingDirection(movingDirection);
    }
}

void game::GameModel::startGame() {
    player = std::make_shared<entity::Player>(); // make player
    for (int i = 0; i < 11; i++) { // make invaders
        invaders.push_back(std::make_shared<entity::Invader>(entity::Position(-3.8 + (0.5 * i), 2.8)));
        invaders.push_back(std::make_shared<entity::Invader>(entity::Position(-3.8 + (0.5 * i), 2.4)));
        invaders.push_back(std::make_shared<entity::Invader>(entity::Position(-3.8 + (0.5 * i), 2.0)));
        invaders.push_back(std::make_shared<entity::Invader>(entity::Position(-3.8 + (0.5 * i), 1.6)));
    }
}

void game::GameModel::update(double dt) {
    _updatePlayer(dt);
    _checkPlayerCollision();
    _updateInvaders(dt);
    _checkInvaderCollision();
    notify();
}

