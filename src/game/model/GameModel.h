//
// Created by Arno Troch on 22/11/2019.
//

#ifndef SPACEINVADERS_GAMEMODEL_H
#define SPACEINVADERS_GAMEMODEL_H

#include "Subject.h"
#include "../../entity/Player.h"
#include "../../entity/Invader.h"

/**
 * Class containing all the game data.
 *
 * The GameModel class is a part of the MVC design pattern. It is used as the 'database' of the game.
 * It contains all the entities and performs modifications to them, like changing their position, health,
 * etc.
 * The GameModel class inherits from the Subject class, as it has to be observed by a GameView object.
 */
class GameModel : public Subject {
private:
    entity::Player::Ptr player; // player

    std::vector<entity::Invader::Ptr> invaders; // enemies

    // std::vector<entity::Shield::Ptr> shields;

public:
    typedef std::shared_ptr<GameModel> Ptr;

    /// default constructor
    GameModel();

    /// default destructor
    virtual ~GameModel() = default;

    /// get Player
    const entity::Player::Ptr &getPlayer() const;

    /// get Invaders
    const std::vector<entity::Invader::Ptr> &getInvaders() const;

    /**
     * move Player to a new position
     * @param position
     */
    void movePlayer(const Position &position);

    /**
     * move Invader i to a new position
     * @param i index of Invader in invaders list
     * @param position new position of invader
     */
    void moveInvader(int i, const Position &position);
};


#endif //SPACEINVADERS_GAMEMODEL_H
