//
// Created by Arno Troch on 19/11/2019.
//

#include "GameView.h"

#include <iostream>

GameView::GameView(GameModel::Ptr model) :
        model(std::move(model)) {
    window.create(sf::VideoMode(1200, 900), "Space Invaders", sf::Style::Default);
}

void GameView::render() {
    window.clear(sf::Color::Black); // clear the window
    sf::Texture texture;
    sf::Sprite sprite;
    // render the player
    texture.loadFromFile(model->getPlayer()->getResourcePath());
    sprite.setTexture(texture);
    sprite.setPosition(static_cast<float>(model->getPlayer()->getPosition().first),
                       static_cast<float>(model->getPlayer()->getPosition().second));
    window.draw(sprite);
    // render the invader
    texture.loadFromFile(model->getInvaders()[0]->getResourcePath());
    sprite.setTexture(texture);
    sprite.setPosition(static_cast<float>(model->getInvaders()[0]->getPosition().first),
                       static_cast<float>(model->getInvaders()[0]->getPosition().second));
    window.draw(sprite);
    // display the window
    window.display();
}


void GameView::onNotify() {
    render();
}

sf::RenderWindow &GameView::getWindow() {
    return window;
}
