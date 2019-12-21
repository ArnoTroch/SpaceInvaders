//
// Created by Arno Troch on 22/11/2019.
//

#ifndef SPACEINVADERS_GAMEMODEL_H
#define SPACEINVADERS_GAMEMODEL_H

#include "Subject.h"
#include "../../entity/Player.h"
#include "../../entity/Invader.h"
#include "../../entity/Bullet.h"

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

    // std::vector<entity::Shield::Ptr> shields; // shields

    void _updatePlayer(double dt);

    void _updateInvaders(double dt);

public:
    using Ptr = std::shared_ptr<GameModel>;

    /**
     * create a GameModel
     */
    GameModel();

    /**
     * default destructor
     */
    virtual ~GameModel() = default;

    /**
     * get player
     * @return player of GameModel
     */
    [[nodiscard]] const entity::Player::Ptr &getPlayer() const;

    /**
     * get invaders
     * @return invaders of GameModel
     */
    [[nodiscard]] const std::vector<entity::Invader::Ptr> &getInvaders() const;

    /**
     * set new moving direction for player
     * @param movingDirection new moving direction for player
     */
    void setPlayerDirection(entity::MovingDirection movingDirection);

    /**
     * set new moving direction for all invaders
     * @param movingDirection new moving direction for all invaders
     */
    void setInvaderDirection(entity::MovingDirection movingDirection);

    /**
     * set Player Bullet, if it doesn't exist yet
     */
    void setPlayerBullet();

    /**
     * start the actual game by creating all necessary entities
     */
    void startGame();

    /**
     * update the game model
     * @param dt delta time
     */
    void update(double dt);
};


#endif //SPACEINVADERS_GAMEMODEL_H
