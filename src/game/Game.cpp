//
// Created by Arno Troch on 18/11/2019.
//

#include "Game.h"

Game::Game() : view() {
    texture.loadFromFile(RESOURCES_DIR + "invaders.png");
    sprite.setTexture(texture);
    dt = 0.0;
    Stopwatch::instance();
}

void Game::run() {
    while (isRunning()) {
        update();
        draw();
        updateDt();
    }
}

void Game::update() {
    view.update();

    const sf::Vector2f &spritePos = sprite.getPosition();
    const double pixelsToMovePerSec = 100;
    const double frameMovement = pixelsToMovePerSec * dt;
    sprite.setPosition(static_cast<float>(spritePos.x + frameMovement), static_cast<float>(spritePos.y));
}

void Game::draw() {
    view.clear();
    view.draw(sprite);
    view.display();
}

bool Game::isRunning() {
    // TODO add code
    return true;
}

void Game::updateDt() {
    dt = Stopwatch::instance().restart();
    std::cout << dt << std::endl;
}
