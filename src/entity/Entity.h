//
// Created by Arno Troch on 18/11/2019.
//

#ifndef SPACEINVADERS_ENTITY_H
#define SPACEINVADERS_ENTITY_H

#include <memory>
#include <string>

#define RESOURCES_DIR std::string("../resources/") // relative path to resources directory

/**
 * This namespace contains everything that is linked to game entities.
 */
namespace entity {
    using Position = std::pair<double, double>;

    /**
     * Abstract base class that every object in the game derives from.
     */
    class Entity {
    private:
        Position position; // position of entity

    public:
        using Ptr = std::shared_ptr<Entity>; // simplify commonly used type

        /**
         * construct an Entity with given position
         * @param position position of Entity
         */
        explicit Entity(Position position);

        /**
         * default destructor
         */
        virtual ~Entity() = default;

        /**
         * get position of Entity
         * @return position of Entity
         */
        [[nodiscard]] const Position &getPosition() const;

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
