//
// Created by Arno Troch on 27/12/2019.
//

#ifndef SPACEINVADERS_TEXTUREEXCEPTION_H
#define SPACEINVADERS_TEXTUREEXCEPTION_H

#include <exception>
#include <string>

/**
 * this namespace contains exceptions that can occur during the game.
 */
namespace game::exception {
    /**
     * Exception class used for when a sf::Texture couldn't be loaded from a file.
     */
    class TextureException : public std::exception {
        std::string path;

    public:
        /**
         * create a TextureException object
         * @param path path to file with texture that couldn't be loaded
         */
        explicit TextureException(std::string path);

        /**
         * get info from exception
         * @return info about TextureException
         */
        [[nodiscard]] const char *what() const noexcept override;

    };
}


#endif //SPACEINVADERS_TEXTUREEXCEPTION_H
