//
// Created by Arno Troch on 29/12/2019.
//

#ifndef SPACEINVADERS_SETTINGS_H
#define SPACEINVADERS_SETTINGS_H

#include <string>
#include <fstream>
#include <iostream>
#include "../exceptions/LevelException.h"
#include "../../../nlohmann/json.hpp"

using json = nlohmann::json;

namespace game::utils {
    /**
     * Class that contains AI game settings, like Shield health, Bullet firing frequency for Invaders, etc.
     */
    class Settings {
    private:
        // entity::Shield health
        int shield_health;

        // multiplier for velocity
        double velocity_multiplier;

        // minimum and maximum number of seconds Invader AI has to wait before shooting again
        std::pair<double, double> shooting_interval;

        // maximum number of Invaders shooting at once
        int max_shooters;

    public:
        /**
         * Create a Settings object
         */
        Settings();

        /**
         * Create a Settings object from a level file
         * @param path relative path to level file that should be loaded
         */
        explicit Settings(const std::string &path);

        /**
         * default destructor
         */
        virtual ~Settings() = default;

        /**
         * load new settings from level file
         * @param path relative path to level file
         */
        void loadNewSettings(const std::string &path);

        /**
         * get shield health
         * @return shield health for Shields
         */
        [[nodiscard]] int getShieldHealth() const;

        /**
         * get velocity multiplier
         * @return velocity multiplier for Invaders
         */
        [[nodiscard]] double getVelocityMultiplier() const;

        /**
         * get shooting interval
         * @return shooting interval for Invaders. This is a time interval in which the Invaders
         * are allowed to shoot
         */
        [[nodiscard]] const std::pair<double, double> &getShootingInterval() const;

        /**
         * get maximum amount of shooters
         * @return maximum amount of shooters per time interval
         */
        [[nodiscard]] int getMaxShooters() const;
    };
}


#endif //SPACEINVADERS_SETTINGS_H
