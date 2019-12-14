//
// Created by Arno Troch on 25/11/2019.
//

#ifndef SPACEINVADERS_TRANSFORMATION_H
#define SPACEINVADERS_TRANSFORMATION_H

#include <memory>

/**
 * Class used to transform entity positions in GameModel to positions for the GameView.
 *
 * The Transformation class converts positions from the 2D game world space of [-4,4] x [-3,3] to the
 * visible 2D pixel values.
 * The GameModel only uses the [-4,4] x [-3,3] coordinate system and doesn't know anything about the
 * actual pixel resolution of the GameView screen.
 * This class is a singleton class.
 */
class Transformation {
private:
    Transformation() = default;

public:
    /// default destructor
    virtual ~Transformation() = default;

    /// call static instance of Transformation class
    static Transformation &instance();

};


#endif //SPACEINVADERS_TRANSFORMATION_H
