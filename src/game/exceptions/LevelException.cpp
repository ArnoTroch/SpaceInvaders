//
// Created by Arno Troch on 05/01/2020.
//

#include "LevelException.h"

game::exception::LevelException::LevelException(std::string path) : path(std::move(path)) {}

const char *game::exception::LevelException::what() const noexcept {
    return ("Error: level with path \'" + path + "\' could not be opened.").c_str();
}
