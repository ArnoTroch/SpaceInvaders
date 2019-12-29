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
    // move player with current velocity and direction
    player->move(dt);
    // update player bullet if one has been fired
    if (auto pbullet = player->getBullet().lock()) {
        if (pbullet->isPossibleMove(dt) && pbullet->alive()) {
            pbullet->move(dt); // move bullet if possible
        } else {
            player->removeBullet(); // if move not possible, remove bullet
        }
    }
    // check player collision with invaders and invader bullets
    for (entity::Invader::Ptr &inv: invaders) {
        // check if player was hit by invader bullet
        if (auto ibullet = inv->getBullet().lock()) {
            if (_entityCollision(player, ibullet)) {
                player->hit();
                ibullet->hit();
            }
        }
        // check if player was hit by invader
        if (_entityCollision(player, inv)) {
            while (player->alive()) player->hit();
            state = State::GAME_OVER;
            return;
        }
    }
    // if player dies, game is over
    if (!player->alive()) {
        state = State::GAME_OVER;
    }
}

void game::GameModel::_updateInvaders(double dt) {
    for (entity::Invader::Ptr &inv: invaders) {
        // move invader with current velocity and direction
        inv->move(dt);
        // update invader bullet if one has been fired
        if (auto bullet = inv->getBullet().lock()) {
            if (bullet->isPossibleMove(dt) && bullet->alive()) {
                bullet->move(dt); // move bullet if possible
            } else {
                inv->removeBullet(); // if move not possible, remove bullet
            }
        }
        // check if invader was hit by player bullet
        if (auto pbullet = player->getBullet().lock()) {
            if (_entityCollision(inv, pbullet)) {
                inv->hit();
                pbullet->hit();
            }
        }
    }
    // remove invaders that died
    auto inv = invaders.begin();
    while (inv != invaders.end()) {
        if (!(*inv)->alive()) {
            inv = invaders.erase(inv);
        } else {
            ++inv;
        }
    }
    // if there are no invaders left, game is over
    if (invaders.empty()) {
        setState(State::GAME_OVER);
    }
}

void game::GameModel::_updateShields() {
    // check shields collision
    for (entity::Shield::Ptr &shld: shields) {
        // check if shield was hit by player bullet
        if (auto pbullet = player->getBullet().lock()) {
            if (_entityCollision(shld, pbullet)) {
                pbullet->hit();
                shld->hit();
            }
        }
        for (entity::Invader::Ptr &inv: invaders) {
            // check if shield was hit by invader bullet
            if (auto ibullet = inv->getBullet().lock()) {
                if (_entityCollision(shld, ibullet)) {
                    ibullet->hit();
                    shld->hit();
                }
            }
            // check if shield was hit by invader
            if (_entityCollision(shld, inv)) {
                while (shld->alive()) {
                    shld->hit();
                }
            }
        }
    }
    // remove shields that died
    auto sh = shields.begin();
    while (sh != shields.end()) {
        if (!(*sh)->alive()) {
            sh = shields.erase(sh);
        } else {
            ++sh;
        }
    }
}

bool game::GameModel::_entityCollision(const entity::Entity::Ptr &e1, const entity::Entity::Ptr &e2) {
    // top left and bottom right coordinates for e1
    entity::Position tl1 = {e1->getPosition().first - (e1->getDimension().first / 2),
                            e1->getPosition().second + (e1->getDimension().second / 2)};
    entity::Position br1 = {e1->getPosition().first + (e1->getDimension().first / 2),
                            e1->getPosition().second - (e1->getDimension().second / 2)};

    // top left and bottom right coordinates for e2
    entity::Position tl2 = {e2->getPosition().first - (e2->getDimension().first / 2),
                            e2->getPosition().second + (e2->getDimension().second / 2)};
    entity::Position br2 = {e2->getPosition().first + (e2->getDimension().first / 2),
                            e2->getPosition().second - (e2->getDimension().second / 2)};

    // check if e1 position overlaps with e2
    return (tl1.first < br2.first && tl2.first < br1.first && br2.second < tl1.second && br1.second < tl2.second);
}

// ----------------//
// public methods
// ----------------//
game::GameModel::GameModel() : state(State::INITIALIZING) {}

const entity::Player::Ptr &game::GameModel::getPlayer() const {
    return player;
}

const std::vector<entity::Invader::Ptr> &game::GameModel::getInvaders() const {
    return invaders;
}

const std::vector<entity::Shield::Ptr> &game::GameModel::getShields() const {
    return shields;
}

game::GameModel::State game::GameModel::getState() const {
    return state;
}

void game::GameModel::setState(game::GameModel::State s) {
    GameModel::state = s;
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
    for (int i = 0; i < 11; ++i) { // make invaders
        invaders.push_back(std::make_shared<entity::Invader>(entity::Position(-3.8 + (0.5 * i), 2.8)));
        invaders.push_back(std::make_shared<entity::Invader>(entity::Position(-3.8 + (0.5 * i), 2.4)));
        invaders.push_back(std::make_shared<entity::Invader>(entity::Position(-3.8 + (0.5 * i), 2.0)));
        invaders.push_back(std::make_shared<entity::Invader>(entity::Position(-3.8 + (0.5 * i), 1.6)));
    }
    for (int s = 0; s < 4; ++s) { // make shields
        shields.push_back(std::make_shared<entity::Shield>(entity::Position(-2.4 + (1.6 * s), -2)));
    }
}

void game::GameModel::update(double dt) {
    switch (state) {
        case State::INITIALIZING:
            state = State::TITLE_SCREEN;
            notify();
            break;
        case State::TITLE_SCREEN:
            break;
        case State::GAME_RUNNING:
            _updatePlayer(dt);
            _updateInvaders(dt);
            _updateShields();
            notify();
            break;
        case State::GAME_OVER:
            break;
    }
}
