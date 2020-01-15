//
// Created by Arno Troch on 27/12/2019.
//

#ifndef SPACEINVADERS_RESOURCELIBRARY_H
#define SPACEINVADERS_RESOURCELIBRARY_H

#include <map>
#include <SFML/Graphics.hpp>
#include <memory>
#include "../exceptions/TextureException.h"
#include "../exceptions/FontException.h"


namespace game::utils {
    /**
     * This utility class is used in the GameView class to make the usage of SFML textures easier and more efficient.
     */
    class ResourceLibrary {
    private:
        // key = relative path to texture | value = texture
        std::map<std::string, std::shared_ptr<sf::Texture>> textures; // all textures

        std::map<std::string, std::shared_ptr<sf::Font>> fonts; // all fonts

    public:
        /**
         * shared_ptr to sf::Texture is defined as game::utils::ResourceLibrary::Texture_Ptr, in order to
         * simplify commonly used types.
         */
        using Texture_Ptr = std::shared_ptr<sf::Texture>;

        /**
         * shared_ptr to sf::Font is defined as game::utils::ResourceLibrary::Font_Ptr, in order to
         * simplify commonly used types.
         */
        using Font_Ptr = std::shared_ptr<sf::Font>;

        /**
         * create a ResourceLibrary
         */
        ResourceLibrary() = default;

        /**
         * default constructor
         */
        ~ResourceLibrary() = default;

        /**
         * get sf::Texture located at path, and load it if necessary
         * @param path path to texture
         * @return sf::Texture loaded from path
         */
        Texture_Ptr getTexture(const std::string &path);

        /**
         * set or replace texture with key 'path' to value 'texture'
         * @param path key of texture value to be changed
         * @param texture new texture value for key 'path'
         */
        void setTexture(const std::string &path, const Texture_Ptr &texture);

        /**
         * get sf::Font located at path, and load it if necessary
         * @param path path to font
         * @return sf::Font loaded from path
         */
        Font_Ptr getFont(const std::string &path);
    };
}


#endif //SPACEINVADERS_RESOURCELIBRARY_H
