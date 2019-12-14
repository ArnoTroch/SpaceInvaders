//
// Created by Arno Troch on 23/11/2019.
//

#include "GameController.h"
#include <SFML/Graphics.hpp>

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
    }
//    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
//        // shoot
//    }
    else {
        // set player moving direction to IDLE
        model->setPlayerDirection(entity::MovingDirection::IDLE);
    }
}

// ----------------//
// public methods
// ----------------//
GameController::GameController(GameModel::Ptr model) : model(std::move(model)) {}

void GameController::update(double dt) {
    _handlePlayer(); // handle user input
    model->update(dt);
}
