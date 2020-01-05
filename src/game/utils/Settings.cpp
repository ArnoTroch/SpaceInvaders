//
// Created by Arno Troch on 29/12/2019.
//

#include "Settings.h"


game::utils::Settings::Settings() : shield_health(8), velocity_multiplier(1), shooting_interval({1, 3}),
                                    max_shooters(2) {}

game::utils::Settings::Settings(const std::string &path) : Settings() {
    loadNewSettings(path);
}

void game::utils::Settings::loadNewSettings(const std::string &path) {
    std::ifstream ifs;
    // try opening the level file
    ifs.open(path);
    if (!ifs.is_open()) { // if level couldn't be opened, throw exception
        throw exception::LevelException(path);
    } else {
        json j = json::parse(ifs);
        shield_health = j.at("ShieldHealth");
        velocity_multiplier = j.at("VelocityMultiplier");
        shooting_interval.first = j.at("ShootingInterval").at("min");
        shooting_interval.second = j.at("ShootingInterval").at("max");
        max_shooters = j.at("MaxShooters");
    }
}

int game::utils::Settings::getShieldHealth() const {
    return shield_health;
}

double game::utils::Settings::getVelocityMultiplier() const {
    return velocity_multiplier;
}

const std::pair<double, double> &game::utils::Settings::getShootingInterval() const {
    return shooting_interval;
}

int game::utils::Settings::getMaxShooters() const {
    return max_shooters;
}
