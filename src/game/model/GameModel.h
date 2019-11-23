//
// Created by Arno Troch on 22/11/2019.
//

#ifndef SPACEINVADERS_GAMEMODEL_H
#define SPACEINVADERS_GAMEMODEL_H

#include "Subject.h"
#include "../../entity/Entity.h"

class GameModel : public Subject {
private:
    std::vector<entity::Entity::Ptr> entities;

public:
    typedef std::shared_ptr<GameModel> Ptr;

    GameModel();

    virtual ~GameModel() = default;

    const std::vector<entity::Entity::Ptr> &getEntities() const;

    void setEntities(const std::vector<entity::Entity::Ptr> &entities);

    void notify() override;

    void update(double dt);

};


#endif //SPACEINVADERS_GAMEMODEL_H
