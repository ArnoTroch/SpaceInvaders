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
    for (const entity::Entity::Ptr &entity: model->getEntities()) {
        // draw all entities on the window
        sf::Texture texture;
        sf::Sprite sprite;
        texture.loadFromFile(entity->getResourcePath());
        sprite.setTexture(texture);
        sprite.setPosition(static_cast<float>(entity->getPosition().getX()),
                           static_cast<float>(entity->getPosition().getY()));
        window.draw(sprite);
    }
    window.display(); // display the window
}


void GameView::onNotify() {
    render();
}

sf::RenderWindow &GameView::getWindow() {
    return window;
}
