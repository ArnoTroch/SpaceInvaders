//
// Created by Arno Troch on 18/11/2019.
//

#include "Game.h"

Game::Game() : view() {
    texture.loadFromFile(RESOURCES_DIR + "invaders.png");
    sprite.setTexture(texture);
}

void Game::run() {

}

void Game::update() {
    view.update();
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
