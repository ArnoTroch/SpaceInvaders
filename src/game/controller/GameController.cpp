//
// Created by Arno Troch on 23/11/2019.
//

#include "GameController.h"
#include <SFML/Graphics.hpp>
#include <iostream>

// ----------------//
// private methods
// ----------------//
void GameController::_handlePlayer() {
    // check for any useful keyboard input
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        // set player moving direction to LEFT
        model->setPlayerDirection(entity::MovingDirection::LEFT);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        // set player moving direction to RIGHT
        model->setPlayerDirection(entity::MovingDirection::RIGHT);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        // shoot player bullet, if possible
        model->setPlayerBullet();
    } else {
        // set player moving direction to IDLE
        model->setPlayerDirection(entity::MovingDirection::IDLE);
    }
}


void GameController::_handleInvaders(double dt) {
    // AI for moving invaders
    for (const entity::Invader::Ptr &inv: model->getInvaders()) {
        // move invaders
        if (inv->getMovingDirection() == entity::MovingDirection::LEFT ||
            inv->getMovingDirection() == entity::MovingDirection::RIGHT) {
            if (!inv->isPossibleMove(dt)) {
                // if left/right is not possible, move down
                down_distance = 0;
                model->setInvaderDirection(entity::MovingDirection::DOWN);
                // change the next moving direction
                next_move_dir = (next_move_dir == entity::MovingDirection::LEFT ? entity::MovingDirection::RIGHT
                                                                                : entity::MovingDirection::LEFT);
                break;
            }
        } else if (inv->getMovingDirection() == entity::MovingDirection::DOWN) {
            down_distance += (inv->getVelocity() * dt);
            if (down_distance >= 0.1) {
                down_distance = 0;
                model->setInvaderDirection(next_move_dir);
            }
            break;
        }
        // shoot random bullets
        std::random_device random_device;
        std::mt19937 gen(random_device());
        std::uniform_real_distribution<double> dist0(min_shoot_time, max_shoot_time);
        std::uniform_int_distribution<int> dist1(0, 2);
        std::uniform_int_distribution<int> dist2(0, model->getInvaders().size() - 1);
        if (shoot_time > dist0(gen)) {
            shoot_time = 0;
            int n = dist1(gen);
            // shoot n times with random invaders
            for (int i = 0; i < n; ++i) {
                int k = dist2(gen);
                model->invaders[k]->shoot();
            }
        }
    }
    shoot_time += dt;
}

// ----------------//
// public methods
// ----------------//
GameController::GameController(GameModel::Ptr model) : model(std::move(model)), down_distance(0), min_shoot_time(1),
                                                       max_shoot_time(3), shoot_time(1),
                                                       next_move_dir(entity::MovingDirection::RIGHT) {}

void GameController::update(double dt) {
    _handlePlayer(); // handle user input for player
    _handleInvaders(dt); // handle AI for invaders
    model->update(dt);
}

