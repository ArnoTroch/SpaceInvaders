//
// Created by Arno Troch on 23/11/2019.
//

#include "GameController.h"
#include <SFML/Graphics.hpp>

// ----------------//
// private methods
// ----------------//
void GameController::_handlePlayer(double dt) {
    // check for any useful keyboard input
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        // move player left
        Position new_player_pos = model->getPlayer()->getPosition();
        new_player_pos.setX(new_player_pos.getX() - (model->getPlayer()->getVelocity() * dt));
        model->movePlayer(new_player_pos);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        // move player right
        Position new_player_pos = model->getPlayer()->getPosition();
        new_player_pos.setX(new_player_pos.getX() + (model->getPlayer()->getVelocity() * dt));
        model->movePlayer(new_player_pos);
    } //else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
    // shoot
    //}
}

void GameController::_handleInvaders(double dt) {
    // TODO make actual AI
    entity::Invader::Ptr inv = model->getInvaders()[0];
    if ((inv->getMovingDirection() == entity::InvaderMovingDirection::left && inv->getPosition().getX() > 200) ||
        inv->getPosition().getX() > 800) {
        // move invader left
        inv->setMovingDirection(entity::InvaderMovingDirection::left);
        Position new_invader_pos = Position(inv->getPosition().getX() - (inv->getVelocity() * dt),
                                            inv->getPosition().getY());
        model->moveInvader(0, new_invader_pos);
    } else if (
            (inv->getMovingDirection() == entity::InvaderMovingDirection::right && inv->getPosition().getX() < 800) ||
            inv->getPosition().getX() < 200) {
        // move invader right
        inv->setMovingDirection(entity::InvaderMovingDirection::right);
        Position new_invader_pos = Position(inv->getPosition().getX() + (inv->getVelocity() * dt),
                                            inv->getPosition().getY());
        model->moveInvader(0, new_invader_pos);
    }
}

// ----------------//
// public methods
// ----------------//
GameController::GameController(GameModel::Ptr model) : model(std::move(model)) {}

void GameController::update(double dt) {
    _handlePlayer(dt); // handle user input and move player if necessary
    _handleInvaders(dt); // handle invaders (AI)
}
