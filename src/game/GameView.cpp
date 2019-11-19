//
// Created by Arno Troch on 19/11/2019.
//

#include "GameView.h"

GameView::GameView() :
        window(sf::VideoMode(800, 600), "Space Invaders", sf::Style::Titlebar) {}

void GameView::update() {
    sf::Event event{}; // 3
    if (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void GameView::draw(const sf::Drawable &drawable) {
    window.draw(drawable);
}

void GameView::clear() {
    window.clear(sf::Color::White);
}

void GameView::display() {
    window.display();
}

