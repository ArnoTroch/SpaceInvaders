//
// Created by Arno Troch on 23/11/2019.
//

#include "Invader.h"

entity::Invader::Invader(const Position &position) : Creature(position, 100) {}

std::string entity::Invader::getResourcePath() {
    return RESOURCES_DIR + "invader.png";
}
