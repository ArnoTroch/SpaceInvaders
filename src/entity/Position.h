//
// Created by Arno Troch on 22/11/2019.
//

#ifndef SPACEINVADERS_POSITION_H
#define SPACEINVADERS_POSITION_H


class Position {
private:
    double x, y;

public:
    Position(double x, double y);

    double getX() const;

    void setX(double x);

    double getY() const;

    void setY(double y);
};


#endif //SPACEINVADERS_POSITION_H
