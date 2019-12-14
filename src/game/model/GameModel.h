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
 * etc. The dimensions of the game model world are [-4,4] x [-3,3], so the game model will know nothing about
 * the actual pixel resolution of the screen. The conversion from this coordinate systems to the pixel values
 * will be done by the Transformation class.
 * The GameModel class inherits from the Subject class, as it has to be observed by a GameView object.
 */
class GameModel : public Subject {
private:
    entity::Player::Ptr player; // player

    std::vector<entity::Invader::Ptr> invaders; // enemies

    // std::vector<entity::Shield::Ptr> shields;

    void _movePlayer(double dt);

    void _moveInvaders(double dt);

public:
    using Ptr = std::shared_ptr<GameModel>;

    /// default constructor
    GameModel();

    /// default destructor
    virtual ~GameModel() = default;

    /// get player
    [[nodiscard]] const entity::Player::Ptr &getPlayer() const;

    /// get invaders
    [[nodiscard]] const std::vector<entity::Invader::Ptr> &getInvaders() const;

    /**
     * change player moving direction
     * @param movingDirection new moving direction of player
     */
    void setPlayerDirection(entity::MovingDirection movingDirection);

    /**
     * update the game model
     * @param dt delta time
     */
    void update(double dt);
};


#endif //SPACEINVADERS_GAMEMODEL_H
