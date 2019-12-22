//
// Created by Arno Troch on 19/11/2019.
//

#include "GameView.h"

#include <iostream>

// ----------------//
// private methods
// ----------------//
void game::GameView::_adjustSprite(sf::Sprite &sprite, const entity::Entity::Ptr &entity) {
    // adjust sprite origin, position and scale
    sprite.setOrigin(static_cast<float>(sprite.getTexture()->getSize().x) / 2 * sprite.getScale().x,
                     static_cast<float>(sprite.getTexture()->getSize().y) / 2 * sprite.getScale().y);
    sprite.setPosition(static_cast<float>(entity->getPosition().first),
                       static_cast<float>(entity->getPosition().second));
    Transformation::instance().transform(sprite, entity);
}

void game::GameView::_renderTitleScreen() {
    window.clear(sf::Color(30, 30, 30));
    // set background image
    sf::Texture bg;
    bg.loadFromFile("../resources/titlescreen.png");
    sf::Sprite background(bg);
    background.setScale(static_cast<float>(window.getSize().x) / bg.getSize().x,
                        static_cast<float>(window.getSize().y) / bg.getSize().y);
    window.draw(background);
    // load font
    sf::Font font;
    font.loadFromFile("../resources/aircruiserlight.ttf");
    // make and draw title
    sf::Text title("Space Invaders", font, window.getSize().x / 12);
    title.setPosition((window.getSize().x - title.getLocalBounds().width) / 2,
                      (window.getSize().y - title.getLocalBounds().height) / 3);
    window.draw(title);
    // make and draw instructions
    sf::Text text("Press space to start", font, window.getSize().x / 40);
    text.setPosition((window.getSize().x - text.getLocalBounds().width) / 2,
                     (window.getSize().y - title.getLocalBounds().height - 10));
    window.draw(text);
    window.display();
}

void game::GameView::_renderGameplay() {
    window.clear(sf::Color::Black); // clear the window
    // set background image
    sf::Texture bg;
    bg.loadFromFile("../resources/gamescreen.png");
    sf::Sprite background(bg);
    background.setScale(static_cast<float>(window.getSize().x) / bg.getSize().x,
                        static_cast<float>(window.getSize().y) / bg.getSize().y);
    window.draw(background);
    sf::Texture playerTexture, invaderTexture, bulletTexture;
    playerTexture.loadFromFile(entity::Player().getResourcePath());
    invaderTexture.loadFromFile(entity::Invader({0, 0}).getResourcePath());
    bulletTexture.loadFromFile(entity::Bullet({0, 0}, entity::MovingDirection::IDLE).getResourcePath());
    // create and draw the player and player bullet sprite (if player is alive)
    if (model->getPlayer()->alive()) {
        // draw player
        sf::Sprite playerSprite;
        playerSprite.setTexture(playerTexture);
        _adjustSprite(playerSprite, model->getPlayer());
        window.draw(playerSprite);
        // bullet
        if (auto bullet = model->getPlayer()->getBullet().lock()) {
            sf::Sprite bulletSprite;
            bulletSprite.setTexture(bulletTexture);
            _adjustSprite(bulletSprite, bullet);
            window.draw(bulletSprite);
        }
    }
    // create and draw the invader and bullet sprites
    for (const entity::Invader::Ptr &inv: model->getInvaders()) {
        if (inv->alive()) {
            // draw invader
            sf::Sprite invaderSprite;
            invaderSprite.setTexture(invaderTexture);
            _adjustSprite(invaderSprite, inv);
            window.draw(invaderSprite);
            // bullet
            if (auto bullet = inv->getBullet().lock()) {
                sf::Sprite bulletSprite;
                bulletSprite.setTexture(bulletTexture);
                _adjustSprite(bulletSprite, bullet);
                window.draw(bulletSprite);
            }
        } else {
            std::cout << "dead invader" << std::endl;
        }
    }
    window.display(); // display the window
}

void game::GameView::_renderGameOver() {

}

// ----------------//
// public methods
// ----------------//
game::GameView::GameView(game::GameModel::Ptr model) :
        model(std::move(model)) {
    window.create(sf::VideoMode(1200, 900), "Space Invaders", sf::Style::Default);
}

void game::GameView::render() {
    switch (model->getState()) {
        case GameModel::State::TITLE_SCREEN:
            _renderTitleScreen();
            break;
        case GameModel::State::GAME_RUNNING:
            _renderGameplay();
            break;
        case GameModel::State::GAME_OVER:
            _renderGameOver();
            break;
    }
}


void game::GameView::onNotify() {
    render();
}

sf::RenderWindow &game::GameView::getWindow() {
    return window;
}

