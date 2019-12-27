//
// Created by Arno Troch on 27/12/2019.
//

#include "TextureException.h"

#include <utility>

game::exception::TextureException::TextureException(std::string path) : path(std::move(path)) {}

const char *game::exception::TextureException::what() const noexcept {
    return ("Texture not loaded: texture with path \'" + path + "\' was not found.").c_str();
}
