//
// Created by Arno Troch on 22/11/2019.
//

#ifndef SPACEINVADERS_GAMEMODEL_H
#define SPACEINVADERS_GAMEMODEL_H

#include "Subject.h"
#include "../../entity/Player.h"
#include "../../entity/Invader.h"

class GameModel : public Subject {
private:
    entity::Player::Ptr player; // player

    std::vector<entity::Invader::Ptr> invaders; // enemies

    // std::vector<entity::Shield::Ptr> shields;

public:
    typedef std::shared_ptr<GameModel> Ptr;

    GameModel();

    virtual ~GameModel() = default;

    const entity::Player::Ptr &getPlayer() const;

    const std::vector<entity::Invader::Ptr> &getInvaders() const;

    void movePlayer(const Position &position);

    void moveInvader(int i, const Position &position);
};


#endif //SPACEINVADERS_GAMEMODEL_H
