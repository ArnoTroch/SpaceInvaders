//
// Created by Arno Troch on 27/12/2019.
//

#include "ResourceLibrary.h"

game::utils::ResourceLibrary::Texture_Ptr game::utils::ResourceLibrary::getTexture(const std::string &path) {
    if (textures[path] == nullptr) {
        // texture isn't loaded yet, so load it
        Texture_Ptr texture = std::make_shared<sf::Texture>();
        // if file is not found, throw exception
        if (!texture->loadFromFile(path)) {
            throw game::exception::TextureException(path);
        }
        textures[path] = texture;
    }
    return textures[path];
}

void game::utils::ResourceLibrary::setTexture(const std::string &path, const Texture_Ptr &texture) {
    textures[path] = texture;
}

game::utils::ResourceLibrary::Font_Ptr game::utils::ResourceLibrary::getFont(const std::string &path) {
    if (fonts[path] == nullptr) {
        // texture isn't loaded yet, so load it
        Font_Ptr font = std::make_shared<sf::Font>();
        // if file is not found, throw exception
        if (!font->loadFromFile(path)) {
            throw game::exception::FontException(path);
        }
        fonts[path] = font;
    }
    return fonts[path];
}
