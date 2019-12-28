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

void game::GameView::_drawBackground(const std::string &path) {
    utils::ResourceLibrary::Texture_Ptr bg;
    try { // try loading and/or applying texture
        bg = resources.getTexture(path);
    } catch (exception::TextureException &e) {
        std::cerr << e.what() << std::endl;
        // if texture can't be found, use a "dummy texture"
        resources.setTexture(path, std::make_shared<sf::Texture>());
        return;
    }
    sf::Sprite background(*bg);
    background.setScale(Transformation::instance().getWindowSize().first / bg->getSize().x,
                        Transformation::instance().getWindowSize().second / bg->getSize().y);
    window.draw(background);
}

void game::GameView::_drawSprite(const entity::Entity::Ptr &entity) {
    sf::Sprite sprite;
    utils::ResourceLibrary::Texture_Ptr texture = std::make_shared<sf::Texture>();
    try {
        texture = resources.getTexture(entity->getResourcePath());
    } catch (exception::TextureException &e) {
        // if texture cannot be loaded, an sf::Image is made and saved in the resources class
        std::cerr << e.what() << std::endl;
        sf::Image img;
        if (auto player_ptr = std::dynamic_pointer_cast<entity::Player>(entity)) {
            img.create(10, 10, sf::Color::Green);
        } else {
            img.create(10, 10, sf::Color::White);
        }
        texture->loadFromImage(img);
        resources.setTexture(entity->getResourcePath(), texture);
    }
    sprite.setTexture(*texture);
    _adjustSprite(sprite, entity);
    window.draw(sprite);
}

void game::GameView::_renderTitleScreen() {
    window.clear(sf::Color(30, 30, 30));
    // set background image
    _drawBackground("../resources/backgrounds/titlescreen.png");
    // load font
    try {
        utils::ResourceLibrary::Font_Ptr font(resources.getFont("../resources/fonts/aircruiserlight.ttf"));
        // make and draw title
        sf::Text title("Space Invaders", *font,
                       static_cast<unsigned int>(Transformation::instance().getWindowSize().first / 12));
        title.setPosition((Transformation::instance().getWindowSize().first - title.getLocalBounds().width) / 2,
                          (Transformation::instance().getWindowSize().second - title.getLocalBounds().height) / 3);
        window.draw(title);
        // make and draw instructions
        sf::Text text("Press space to start", *font,
                      static_cast<unsigned int>(Transformation::instance().getWindowSize().first / 40));
        text.setPosition((Transformation::instance().getWindowSize().first - text.getLocalBounds().width) / 2,
                         (Transformation::instance().getWindowSize().second - text.getLocalBounds().height * 2));
        window.draw(text);
        window.display();
    } catch (exception::FontException &e) {
        std::cerr << e.what() << std::endl;
        std::cout << "––––––––––––––––––––––––\n"
                     "–––– SPACE INVADERS ––––\n"
                     "– Press space to start –\n"
                     "––––––––––––––––––––––––\n" << std::endl;
    }
}

void game::GameView::_renderGameplay() {
    window.clear(sf::Color::Black); // clear the window
    // set background image
    _drawBackground("../resources/backgrounds/gamescreen.png");
    // draw player
    _drawSprite(model->getPlayer());
    // draw player bullet if it exists
    if (auto bullet = model->getPlayer()->getBullet().lock()) {
        _drawSprite(bullet);
    }
    // draw invaders
    for (const entity::Invader::Ptr &inv: model->getInvaders()) {
        // draw invader
        _drawSprite(inv);
        // draw invader bullet if it exists
        if (auto bullet = inv->getBullet().lock()) {
            _drawSprite(bullet);
        }
    }
    window.display(); // display the window
}

void game::GameView::_renderGameOver() {
    window.clear(sf::Color::Black);
    // load font
    try {
        utils::ResourceLibrary::Font_Ptr font;
        font = resources.getFont("../resources/fonts/aircruiserlight.ttf");
        // make and draw title
        sf::Text msg("GAME\nOVER", *font,
                     static_cast<unsigned int>(Transformation::instance().getWindowSize().first / 5));
        msg.setPosition((Transformation::instance().getWindowSize().first - msg.getLocalBounds().width) / 2,
                        (Transformation::instance().getWindowSize().second - msg.getLocalBounds().height) / 3);
        window.draw(msg);
        // make and draw end message
        std::string endmessage = "Better luck next time!";
        if (model->getInvaders().empty()) {
            endmessage = "You won!";
        }
        sf::Text text(endmessage, *font,
                      static_cast<unsigned int>(Transformation::instance().getWindowSize().first / 20));
        text.setPosition((Transformation::instance().getWindowSize().first - text.getLocalBounds().width) / 2,
                         (Transformation::instance().getWindowSize().second - text.getLocalBounds().height * 2));
        window.draw(text);
        window.display();
    } catch (exception::FontException &e) {
        std::cerr << e.what() << std::endl;
        std::cout << "––––––––––––––––––––––––\n"
                     "–––––– GAME  OVER ––––––" << std::endl;
        if (model->getInvaders().empty()) {
            std::cout << "––––––– You won! –––––––\n"
                         "––––––––––––––––––––––––\n" << std::endl;
        } else {
            std::cout << "–Better luck next time!–\n"
                         "––––––––––––––––––––––––\n" << std::endl;
        }
    }
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
        default:
            break;
    }
}

void game::GameView::onNotify() {
    render();
}

sf::RenderWindow &game::GameView::getWindow() {
    return window;
}

