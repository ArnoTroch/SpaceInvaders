//
// Created by Arno Troch on 22/11/2019.
//

#include "GameModel.h"
#include "../../entity/Player.h"
#include "../../entity/Invader.h"

GameModel::GameModel() {
    entities.push_back(std::make_shared<entity::Player>(Position(200, 200)));
    entities.push_back(std::make_shared<entity::Invader>(Position(400, 400)));
}

const std::vector<entity::Entity::Ptr> &GameModel::getEntities() const {
    return entities;
}

void GameModel::setEntities(const std::vector<entity::Entity::Ptr> &vec_entities) {
    GameModel::entities = vec_entities;
}

void GameModel::notify() {
    for (Observer::Ptr &obs: observers) {
        obs->onNotify();
    }
}

void GameModel::update(double dt) {
    // update position of entities
    for (entity::Entity::Ptr &entity: entities) {
        if (entity::Player::Ptr player = std::dynamic_pointer_cast<entity::Player>(entity)) {
            Position new_pos = player->getPosition();
            new_pos.setX(new_pos.getX() + (player->getVelocity() * dt));
            entity->setPosition(new_pos); // change player position
        } else if (entity::Invader::Ptr invader = std::dynamic_pointer_cast<entity::Invader>(entity)) {
            Position new_pos = invader->getPosition();
            new_pos.setX(new_pos.getX() + (invader->getVelocity() * dt));
            new_pos.setY(new_pos.getY() + (invader->getVelocity() * dt));
            entity->setPosition(new_pos); // change invader position
        }
    }
    notify();
}
