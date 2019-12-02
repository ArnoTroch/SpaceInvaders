//
// Created by Arno Troch on 22/11/2019.
//

#ifndef SPACEINVADERS_POSITION_H
#define SPACEINVADERS_POSITION_H

/**
 * Class used to keep the position of an Entity.
 *
 * This class contains the x and y coordinate of a certain Entity.
 */
class Position {
private:
    double x, y;

public:

    /// constructor initialises a Position with given x and y coordinate
    Position(double x, double y);

    /// get x coordinate
    double getX() const;

    /// set new x coordinate
    void setX(double x);

    /// get y coordinate
    double getY() const;

    /// set new y coordinate
    void setY(double y);
};


#endif //SPACEINVADERS_POSITION_H
