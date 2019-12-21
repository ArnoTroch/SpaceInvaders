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
    static double down_distance = 0;
    static entity::MovingDirection next_move_dir = entity::MovingDirection::RIGHT;
    for (const entity::Invader::Ptr &inv: model->getInvaders()) {
        if (inv->getMovingDirection() == entity::MovingDirection::LEFT ||
            inv->getMovingDirection() == entity::MovingDirection::RIGHT) {
            if (!inv->isPossibleMove(dt)) {
                // if left/right is not possible, move down
                down_distance = 0;
                model->setInvaderDirection(entity::MovingDirection::DOWN);
                // change the next moving direction
                if (next_move_dir == entity::MovingDirection::LEFT) {
                    next_move_dir = entity::MovingDirection::RIGHT;
                } else if (next_move_dir == entity::MovingDirection::RIGHT) {
                    next_move_dir = entity::MovingDirection::LEFT;
                }
                break;
            }
        } else if (inv->getMovingDirection() == entity::MovingDirection::DOWN) {
            down_distance += (inv->getVelocity() * dt);
            if (down_distance >= 0.1) {
                std::cout << down_distance << std::endl;
                down_distance = 0;
                model->setInvaderDirection(next_move_dir);
            }
            break;
        }
    }
}

// ----------------//
// public methods
// ----------------//
GameController::GameController(GameModel::Ptr model) : model(std::move(model)) {}

void GameController::update(double dt) {
    _handlePlayer(); // handle user input for player
    _handleInvaders(dt); // handle AI for invaders
    model->update(dt);
}

