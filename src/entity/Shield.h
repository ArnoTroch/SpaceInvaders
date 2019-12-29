//
// Created by Arno Troch on 29/12/2019.
//

#ifndef SPACEINVADERS_SHIELD_H
#define SPACEINVADERS_SHIELD_H

#include "Entity.h"

namespace entity {

    /**
     * Class used to represent the shields in the game.
     *
     * This class inherits from the Entity class
     */
    class Shield : public Entity {
    public:
        /**
         * shared_ptr to Shield is defined as entity::Shield::Ptr, in order to
         * simplify commonly used types.
         */
        using Ptr = std::shared_ptr<Shield>;

        /**
         * create a Shield
         * @param position position of new Shield
         */
        explicit Shield(Position position);

        /**
         * default destructor
         */
        ~Shield() override = default;

        /**
         * get relative path to resources
         * @return relative path to resources for Shield
         */
        std::string getResourcePath() override;
    };
}


#endif //SPACEINVADERS_SHIELD_H
