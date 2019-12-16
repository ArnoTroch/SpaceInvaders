//
// Created by Arno Troch on 19/11/2019.
//

#include "GameView.h"

#include <iostream>

// ----------------//
// private methods
// ----------------//
void GameView::_adjustPlayerSprite(sf::Sprite &sprite, const entity::Player::Ptr &player) {
    // adjust player sprite origin, position and scale
    sprite.setOrigin(static_cast<float>(sprite.getTexture()->getSize().x) / 2 * sprite.getScale().x,
                     static_cast<float>(sprite.getTexture()->getSize().y) / 2 * sprite.getScale().y);
    sprite.setPosition(static_cast<float>(player->getPosition().first),
                       static_cast<float>(player->getPosition().second));
    Transformation::instance().transform(sprite, player);
}

void GameView::_adjustInvaderSprite(sf::Sprite &sprite, const entity::Invader::Ptr &invader) {
    // adjust invader sprite origin, position and scale
    sprite.setOrigin(static_cast<float>(sprite.getTexture()->getSize().x) / 2 * sprite.getScale().x,
                     static_cast<float>(sprite.getTexture()->getSize().y) / 2 * sprite.getScale().y);
    sprite.setPosition(static_cast<float>(invader->getPosition().first),
                       static_cast<float>(invader->getPosition().second));
    Transformation::instance().transform(sprite, invader);

}

// ----------------//
// public methods
// ----------------//
GameView::GameView(GameModel::Ptr model) :
        model(std::move(model)) {
    window.create(sf::VideoMode(1200, 900), "Space Invaders", sf::Style::Default);
}

void GameView::render() {
    sf::Texture texture;
    window.clear(sf::Color::Black); // clear the window
    // create and draw the player sprite
    sf::Sprite playerSprite;
    texture.loadFromFile(model->getPlayer()->getResourcePath());
    playerSprite.setTexture(texture);
    _adjustPlayerSprite(playerSprite, model->getPlayer());
    window.draw(playerSprite);
    // create and draw the invader sprites
    for (const entity::Invader::Ptr &inv: model->getInvaders()) {
        sf::Sprite invaderSprite;
        texture.loadFromFile(inv->getResourcePath());
        invaderSprite.setTexture(texture);
        _adjustInvaderSprite(invaderSprite, inv);
        window.draw(invaderSprite);

    }
    window.display(); // display the window
}


void GameView::onNotify() {
    render();
}

sf::RenderWindow &GameView::getWindow() {
    return window;
}

