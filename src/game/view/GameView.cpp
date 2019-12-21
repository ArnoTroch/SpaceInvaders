//
// Created by Arno Troch on 19/11/2019.
//

#include "GameView.h"

#include <iostream>

// ----------------//
// private methods
// ----------------//
void GameView::_adjustSprite(sf::Sprite &sprite, const entity::Entity::Ptr &entity) {
    // adjust sprite origin, position and scale
    sprite.setOrigin(static_cast<float>(sprite.getTexture()->getSize().x) / 2 * sprite.getScale().x,
                     static_cast<float>(sprite.getTexture()->getSize().y) / 2 * sprite.getScale().y);
    sprite.setPosition(static_cast<float>(entity->getPosition().first),
                       static_cast<float>(entity->getPosition().second));
    Transformation::instance().transform(sprite, entity);
}

// ----------------//
// public methods
// ----------------//
GameView::GameView(GameModel::Ptr model) :
        model(std::move(model)) {
    window.create(sf::VideoMode(1200, 900), "Space Invaders", sf::Style::Default);
}

void GameView::render() {
    sf::Texture playerTexture, invaderTexture, bulletTexture;
    playerTexture.loadFromFile(entity::Player().getResourcePath());
    invaderTexture.loadFromFile(entity::Invader({0, 0}).getResourcePath());
    bulletTexture.loadFromFile(entity::Bullet({0, 0}, entity::MovingDirection::IDLE).getResourcePath());
    window.clear(sf::Color::Black); // clear the window

    // create and draw the player and player bullet sprite
    sf::Sprite playerSprite;
    playerSprite.setTexture(playerTexture);
    _adjustSprite(playerSprite, model->getPlayer());
    window.draw(playerSprite);
    if (auto bullet = model->getPlayer()->getBullet().lock()) {
        sf::Sprite bulletSprite;
        bulletSprite.setTexture(bulletTexture);
        _adjustSprite(bulletSprite, bullet);
        window.draw(bulletSprite);
    }

    // create and draw the invader and bullet sprites
    for (const entity::Invader::Ptr &inv: model->getInvaders()) {
        // draw invader
        sf::Sprite invaderSprite;
        invaderSprite.setTexture(invaderTexture);
        _adjustSprite(invaderSprite, inv);
        window.draw(invaderSprite);
        // draw bullets
        if (auto bullet = inv->getBullet().lock()) {
            sf::Sprite bulletSprite;
            bulletSprite.setTexture(bulletTexture);
            _adjustSprite(bulletSprite, bullet);
            window.draw(bulletSprite);
        }
    }
    window.display(); // display the window
}


void GameView::onNotify() {
    render();
}

sf::RenderWindow &GameView::getWindow() {
    return window;
}

