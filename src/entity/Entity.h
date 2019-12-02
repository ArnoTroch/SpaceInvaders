//
// Created by Arno Troch on 18/11/2019.
//

#ifndef SPACEINVADERS_ENTITY_H
#define SPACEINVADERS_ENTITY_H

#include "Position.h"
#include <memory>
#include <string>

#define RESOURCES_DIR std::string("../resources/") // relative path to resources directory

/**
 * This namespace contains everything that is linked to game entities.
 */
namespace entity {

    /**
     * Abstract base class that every object in the game derives from.
     */
    class Entity {
    private:
        Position position; // position of entity

    public:
        typedef std::shared_ptr<Entity> Ptr; // simplify commonly used type

        /**
         * construct an Entity with given position
         * @param position position of Entity
         */
        explicit Entity(const Position &position);

        /**
         * default destructor
         */
        virtual ~Entity() = default;

        /**
         * get position of Entity
         * @return position of Entity
         */
        const Position &getPosition() const;

        /**
         * set position of Entity
         * @param position new position of Entity
         */
        void setPosition(const Position &position);

        /**
         * get relative path containing textures for displaying an Entity
         */
        virtual std::string getResourcePath() = 0;

    };

}

#endif //SPACEINVADERS_ENTITY_H
