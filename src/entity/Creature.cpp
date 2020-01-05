//
// Created by Arno Troch on 23/11/2019.
//

#include "Creature.h"

entity::Creature::Creature(const Position &position, const Dimension &dimension, int health, double velocity,
                           double velocityMultiplier) : Entity(position, dimension, health), velocity(velocity),
                                                        direction(MovingDirection::IDLE),
                                                        velocityMultiplier(velocityMultiplier) {}

double entity::Creature::getVelocity() const {
    return velocity;
}

double entity::Creature::getVelocityMultiplier() const {
    return velocityMultiplier;
}

void entity::Creature::setVelocityMultiplier(double mult) {
    Creature::velocityMultiplier = mult;
}

entity::MovingDirection entity::Creature::getMovingDirection() const {
    return direction;
}

void entity::Creature::setMovingDirection(entity::MovingDirection movingDirection) {
    Creature::direction = movingDirection;
}


bool entity::Creature::isPossibleMove(double dt) const {
    Position new_pos = getPosition();
    switch (direction) {
        case MovingDirection::LEFT:
            new_pos.first -= (getVelocity() * getVelocityMultiplier() * dt);
            break;
        case MovingDirection::RIGHT:
            new_pos.first += (getVelocity() * getVelocityMultiplier() * dt);
            break;
        case MovingDirection::DOWN:
            new_pos.second -= (getVelocity() * getVelocityMultiplier() * dt);
            break;
        case MovingDirection::UP:
            new_pos.second += (getVelocity() * getVelocityMultiplier() * dt);
            break;
        case MovingDirection::IDLE:
            break;
    }
    return abs(new_pos.first) + (getDimension().first / 2) <= MAX_X &&
           abs(new_pos.second) + (getDimension().second / 2) <= MAX_Y;
}

bool entity::Creature::move(double dt) {
    if (!isPossibleMove(dt)) {
        return false;
    }
    Position new_pos = getPosition();
    switch (direction) {
        case MovingDirection::LEFT:
            new_pos.first -= (getVelocity() * getVelocityMultiplier() * dt);
            break;
        case MovingDirection::RIGHT:
            new_pos.first += (getVelocity() * getVelocityMultiplier() * dt);
            break;
        case MovingDirection::DOWN:
            new_pos.second -= (getVelocity() * getVelocityMultiplier() * dt);
            break;
        case MovingDirection::UP:
            new_pos.second += (getVelocity() * getVelocityMultiplier() * dt);
            break;
        case MovingDirection::IDLE:
            break;
    }
    setPosition(new_pos);
    return true;
}
