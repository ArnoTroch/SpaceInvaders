//
// Created by Arno Troch on 22/11/2019.
//

#include "Position.h"

Position::Position(double x, double y) : x(x), y(y) {}

double Position::getX() const {
    return x;
}

void Position::setX(double x_value) {
    Position::x = x_value;
}

double Position::getY() const {
    return y;
}

void Position::setY(double y_value) {
    Position::y = y_value;
}
