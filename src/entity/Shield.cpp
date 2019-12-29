//
// Created by Arno Troch on 29/12/2019.
//

#include "Shield.h"

entity::Shield::Shield(entity::Position position) : Entity(position, {1, 0.5}, 5) {}

std::string entity::Shield::getResourcePath() {
    if (getHealth() == 5) {
        return entity::getResourcesDir() + "entities/wall3.png";
    } else if (getHealth() == 4 || getHealth() == 3) {
        return entity::getResourcesDir() + "entities/wall2.png";
    } else {
        return entity::getResourcesDir() + "entities/wall1.png";
    }
}
