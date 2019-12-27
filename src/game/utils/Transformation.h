//
// Created by Arno Troch on 25/11/2019.
//

#ifndef SPACEINVADERS_TRANSFORMATION_H
#define SPACEINVADERS_TRANSFORMATION_H

#include <memory>
#include <SFML/Graphics.hpp>
#include "../../entity/Entity.h"

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
    Transformation();

    float windowX{}, windowY{};
public:
    /**
     * default destructor
     */
    virtual ~Transformation() = default;

    /**
     * call static instance of Transformation class
     */
    static Transformation &instance();

    /**
     * get current window size
     * @return current window size
     */
    std::pair<float, float> getWindowSize();

    /**
     * set current window size. These values will be used for transforming entity positions from the
     * game model to the window size.
     * @param x window size of x axis
     * @param y window size of y axis
     */
    void setWindowSize(float x, float y);

    /**
     * transform Sprite representing an Entity to fit on the GameView window
     * @param sprite Sprite to be transformed
     * @param entity Entity represented by sprite
     */
    void transform(sf::Sprite &sprite, const entity::Entity::Ptr &entity);

};


#endif //SPACEINVADERS_TRANSFORMATION_H
