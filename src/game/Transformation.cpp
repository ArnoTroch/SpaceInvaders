//
// Created by Arno Troch on 25/11/2019.
//

#include "Transformation.h"

Transformation::Transformation() : windowX(-1), windowY(-1) {}

Transformation &Transformation::instance() {
    static std::unique_ptr<Transformation> sw(new Transformation());
    return *sw;
}

void Transformation::setWindowSize(double x, double y) {
    windowX = x;
    windowY = y;
}

void Transformation::transform(sf::Sprite &sprite, const entity::Entity::Ptr &entity) {
    double sizeX = entity->getDimension().first / 8;    // percentage of space used by entity (on x-axis)
    double sizeY = entity->getDimension().second / 6;   // percentage of space used by entity (on y-axis)
    sprite.setScale(static_cast<float>((sizeX * windowX) / sprite.getTexture()->getSize().x),
                    static_cast<float>((sizeY * windowY) / sprite.getTexture()->getSize().y));
    sprite.setPosition(static_cast<float>(((sprite.getPosition().x + 4) / 8) * windowX),
                       static_cast<float>(((-sprite.getPosition().y + 3) / 6) * windowY));
}
