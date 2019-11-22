//
// Created by Arno Troch on 18/11/2019.
//

#ifndef SPACEINVADERS_ENTITY_H
#define SPACEINVADERS_ENTITY_H

#include "Position.h"
#include <memory>

namespace entity {

    class Entity {
    private:
        Position position;

    public:
        typedef std::shared_ptr<Entity> Ptr; // simplify commonly used type

        explicit Entity(const Position &position);

        virtual ~Entity() = default;

        const Position &getPosition() const;

        void setPosition(const Position &position);

        virtual void getResourcePath() = 0;

    };

}

#endif //SPACEINVADERS_ENTITY_H
