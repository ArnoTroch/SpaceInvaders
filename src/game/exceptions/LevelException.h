//
// Created by Arno Troch on 05/01/2020.
//

#ifndef SPACEINVADERS_LEVELEXCEPTION_H
#define SPACEINVADERS_LEVELEXCEPTION_H

#include <exception>
#include <string>

namespace game::exception {

    /**
     * Exception class that is used when a level file could not be loaded
     */
    class LevelException : public std::exception {
        std::string path;

    public:
        /**
         * create a new LevelException
         * @param path path to level file that couldn't be loaded
         */
        explicit LevelException(std::string path);

        /**
         * get info from exception
         * @return info about LevelException
         */
        [[nodiscard]] const char *what() const noexcept override;
    };

}


#endif //SPACEINVADERS_LEVELEXCEPTION_H
