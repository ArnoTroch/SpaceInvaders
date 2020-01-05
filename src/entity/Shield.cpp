//
// Created by Arno Troch on 29/12/2019.
//

#include "Shield.h"

entity::Shield::Shield(entity::Position position) : Entity(position, {1, 0.5}, 8),
                                                    maxHealth(8) {}

std::string entity::Shield::getResourcePath() {
    double low = floor((static_cast<double>(maxHealth) / 3) + 0.5);
    double avg = floor((static_cast<double>(maxHealth) * 2 / 3) + 0.5);
    if (getHealth() <= low) {
        return entity::getResourcesDir() + "entities/wall1.png";
    } else if (getHealth() <= avg) {
        return entity::getResourcesDir() + "entities/wall2.png";
    } else {
        return entity::getResourcesDir() + "entities/wall3.png";
    }
}

void entity::Shield::setMaxHealth(int maxh) {
    Shield::maxHealth = maxh;
    setHealth(maxh);
}
