//
// Created by Arno Troch on 27/12/2019.
//

#include "FontException.h"

game::exception::FontException::FontException(std::string path) : path(std::move(path)) {}

const char *game::exception::FontException::what() const noexcept {
    return ("Font not loaded: font with path \'" + path + "\' was not found.").c_str();
}
