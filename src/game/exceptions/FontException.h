//
// Created by Arno Troch on 27/12/2019.
//

#ifndef SPACEINVADERS_FONTEXCEPTION_H
#define SPACEINVADERS_FONTEXCEPTION_H

#include <exception>
#include <string>

namespace game::exception {
    /**
     * Exception class used for when a sf::Font couldn't be loaded from a file.
     */
    class FontException : public std::exception {
        std::string path;

    public:
        /**
         * create a new FontException
         * @param path path to file with font that couldn't be loaded
         */
        explicit FontException(std::string path);

        /**
         * get info from exception
         * @return info about FontException
         */
        [[nodiscard]] const char *what() const noexcept override;
    };
}


#endif //SPACEINVADERS_FONTEXCEPTION_H
