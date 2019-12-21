//
// Created by Arno Troch on 18/11/2019.
//

#include "Game.h"

// ----------------//
// private methods
// ----------------//
void Game::_update() {
    controller->update(dt);
}

void Game::_updateDt() {
    dt = Stopwatch::instance().restart();
}


// ----------------//
// public methods
// ----------------//
Game::Game() {
    model = std::make_shared<GameModel>();
    view = std::make_shared<GameView>(model);
    model->addObserver(view);
    controller = std::make_shared<GameController>(model);
    dt = 0.0;
}

void Game::run() {
    Stopwatch::instance();
    Transformation::instance().setWindowSize(view->getWindow().getSize().x, view->getWindow().getSize().y);
    // run the program as long as the window is open
    while (view->getWindow().isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event{};
        while (view->getWindow().pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                view->getWindow().close();
            }
        }
        _update(); // update game model
        _updateDt(); // update delta time
    }
}
