//
// Created by Arno Troch on 23/11/2019.
//

#include "Creature.h"

entity::Creature::Creature(const Position &position, double velocity) : Entity(position), velocity(velocity),
                                                                        direction(MovingDirection::IDLE) {}

double entity::Creature::getVelocity() const {
    return velocity;
}

void entity::Creature::setVelocity(double v) {
    Creature::velocity = v;
}

entity::MovingDirection entity::Creature::getMovingDirection() const {
    return direction;
}

void entity::Creature::setDirection(entity::MovingDirection dir) {
    Creature::direction = dir;
}
