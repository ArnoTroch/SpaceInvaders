//
// Created by Arno Troch on 18/11/2019.
//

#include "Game.h"

Game::Game() {
    model = std::make_shared<GameModel>();
    view = std::make_shared<GameView>(model);
    model->addObserver(view);
    controller = std::make_shared<GameController>(model);
    dt = 0.0;
}

void Game::run() {
    Stopwatch::instance();
    // this code is copied from the SFML tutorials
    // https://www.sfml-dev.org/tutorials/2.4/graphics-draw.php

    // run the program as long as the window is open
    while (view->getWindow().isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event{};
        while (view->getWindow().pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                view->getWindow().close();
        }
        update(); // update game model
        updateDt(); // update delta time
    }
}

void Game::update() {
    controller->update(dt);
}

void Game::updateDt() {
    dt = Stopwatch::instance().restart();
}
