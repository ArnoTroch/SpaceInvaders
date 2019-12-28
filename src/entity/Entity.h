//
// Created by Arno Troch on 18/11/2019.
//

#ifndef SPACEINVADERS_ENTITY_H
#define SPACEINVADERS_ENTITY_H

#include <memory>
#include <string>

/**
 * This namespace contains everything that is linked to game entities.
 */
namespace entity {
    /**
     * maximum value of the x coordinate of an entity
     */
    const int MAX_X = 4;

    /**
     * maximum value of the y coordinate of an entity
     */
    const int MAX_Y = 3;
    /**
     * entity::Position is defined as a pair of doubles, where Position.first = x coordinate,
     * and Position.second = y coordinate.
     */
    using Position = std::pair<double, double>;

    /**
     * entity::Dimension is defined as a pair of doubles, with Dimension.first = width,
     * and Dimension.second = height.
     */
    using Dimension = std::pair<double, double>;

    /**
     * get relative path to directory containing resources
     * @return relative path to resources directory
     */
    std::string getResourcesDir();

    /**
     * Abstract base class that every object in the game derives from.
     */
    class Entity {
    private:
        Position position;

        Dimension dimension;

        int health;

    public:
        /**
         * shared_ptr to Entity is defined as entity::Entity::Ptr, in order to
         * simplify commonly used types.
         */
        using Ptr = std::shared_ptr<Entity>; // simplify commonly used type

        /**
         * create an Entity
         * @param position position of new Entity
         * @param dimension dimension of new Entity
         * @param health health of new Entity
         */
        Entity(Position position, Dimension dimension, int health);

        /**
         * default destructor
         */
        virtual ~Entity() = default;

        /**
         * get position
         * @return position of Entity
         */
        [[nodiscard]] const Position &getPosition() const;

        /**
         * set new position
         * @param position new position of Entity
         */
        void setPosition(const Position &position);

        /**
         * get dimension
         * @return dimension of Entity
         */
        [[nodiscard]] const Dimension &getDimension() const;

        /**
         * reduce health by one
         */
        void hit();

        /**
         * check if Entity has health left
         * @return true if health > 0, false otherwise
         */
        bool alive();

        /**
         * get relative path containing textures for displaying an Entity
         * @return relative path to textures
         */
        virtual std::string getResourcePath() = 0;

    };

}

#endif //SPACEINVADERS_ENTITY_H
