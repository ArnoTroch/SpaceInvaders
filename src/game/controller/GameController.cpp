//
// Created by Arno Troch on 23/11/2019.
//

#include "GameController.h"
#include <SFML/Graphics.hpp>
#include <iostream>

// ----------------//
// private methods
// ----------------//
void game::GameController::_handleTitleScreen() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        _loadLevel();
    }
}

void game::GameController::_handleWaveOver() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        int player_health = model->getPlayer()->getHealth();
        _loadLevel();
        while (model->getPlayer()->getHealth() > player_health) {
            model->player->hit();
        }
    }
}

void game::GameController::_handlePlayer() {
    // check for any useful keyboard input
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        // set player moving direction to LEFT
        model->setPlayerDirection(entity::MovingDirection::LEFT);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        // set player moving direction to RIGHT
        model->setPlayerDirection(entity::MovingDirection::RIGHT);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        // shoot player bullet, if possible
        model->player->shoot();
    } else {
        // set player moving direction to IDLE
        model->setPlayerDirection(entity::MovingDirection::IDLE);
    }
}


void game::GameController::_handleInvaders(double dt) {
    static double down_distance = 0, shoot_time = 1;
    static entity::MovingDirection next_move_dir = entity::MovingDirection::RIGHT;
    // AI for moving invaders
    for (const entity::Invader::Ptr &inv: model->getInvaders()) {
        // move invaders
        if (inv->getMovingDirection() != entity::MovingDirection::DOWN) {
            if (!inv->isPossibleMove(dt)) {
                // if left/right is not possible, move down
                down_distance = 0;
                model->setInvaderDirection(entity::MovingDirection::DOWN);
                // change the next moving direction
                next_move_dir == entity::MovingDirection::LEFT ? next_move_dir = entity::MovingDirection::RIGHT
                                                               : next_move_dir = entity::MovingDirection::LEFT;
                break;
            }
        } else {
            down_distance += (inv->getVelocity() * settings.getVelocityMultiplier() * dt);
            if (down_distance >= 0.1) {
                down_distance = 0;
                model->setInvaderDirection(next_move_dir);
            }
            break;
        }
        // shoot random bullets
        std::random_device random_device;
        std::mt19937 gen(random_device());
        std::uniform_real_distribution<double> dist0(settings.getShootingInterval().first,
                                                     settings.getShootingInterval().second);
        std::uniform_int_distribution<int> dist1(0, settings.getMaxShooters());
        std::uniform_int_distribution<int> dist2(0, static_cast<int>(model->getInvaders().size() - 1));
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

void game::GameController::_loadLevel() {
    model->setup(); // setup basic entities on starting positions
    try { // try to load settings for current level
        settings.loadNewSettings(entity::getResourcesDir() + "levels/level" +
                                 std::to_string(model->getCurrentLevel()) + ".json");
        // set Shield health
        for (entity::Shield::Ptr &shld: model->shields) {
            shld->setMaxHealth(settings.getShieldHealth());
        }
        // set Invader velocity multiplier
        for (entity::Invader::Ptr &inv: model->invaders) {
            inv->setVelocityMultiplier(settings.getVelocityMultiplier());
        }
    } catch (exception::LevelException &e) {
        // if level couldn't be loaded, then default settings will be used (settings for level 1)
        settings = utils::Settings();
        // and user will be notified
        std::cerr << e.what() << std::endl;

    }
}

// ----------------//
// public methods
// ----------------//
game::GameController::GameController(GameModel::Ptr model) : model(std::move(model)) {}

void game::GameController::update(double dt) {
    switch (model->getState()) {
        case GameModel::State::TITLE_SCREEN:
            _handleTitleScreen();
            break;
        case GameModel::State::GAME_RUNNING:
            _handlePlayer(); // handle user input for player
            _handleInvaders(dt); // handle AI for invaders
            break;
        case GameModel::State::WAVE_OVER:
            _handleWaveOver();
            break;
        default:
            break;
    }
    model->update(dt);
}
