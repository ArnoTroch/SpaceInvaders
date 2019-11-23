//
// Created by Arno Troch on 22/11/2019.
//

#include "GameModel.h"
#include "../../entity/Player.h"
#include "../../entity/Invader.h"

GameModel::GameModel() {
    player = std::make_shared<entity::Player>(Position(600, 700));
    invaders.push_back(std::make_shared<entity::Invader>(Position(400, 400)));
}

const entity::Player::Ptr &GameModel::getPlayer() const {
    return player;
}

const std::vector<entity::Invader::Ptr> &GameModel::getInvaders() const {
    return invaders;
}

void GameModel::movePlayer(const Position &position) {
    player->setPosition(position);
    notify();
}

void GameModel::moveInvader(int i, const Position &position) {
    if (i < invaders.size()) {
        invaders[i]->setPosition(position);
    }
    notify();
}

