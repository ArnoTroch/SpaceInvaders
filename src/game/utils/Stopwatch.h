//
// Created by Arno Troch on 19/11/2019.
//

#ifndef SPACEINVADERS_STOPWATCH_H
#define SPACEINVADERS_STOPWATCH_H

#include <memory>
#include <chrono>
/**
 * This namespace contains all classes that are used by the classes in the game namespace. The purpose of those classes
 * is to make usage of commonly used utilities easier.
 *
 */
namespace game::utils {
    /**
     * Singleton class used for measuring time differences between two timestamps.
     *
     */
    class Stopwatch {
    public:
        using Time = std::chrono::system_clock::time_point;

    private:
        Stopwatch();

        Time last_recorded_time;

    public:
        /**
         * default destructor
         */
        virtual ~Stopwatch() = default;

        /**
         * call static instance of Stopwatch
         * @return static instance of Stopwatch
         */
        static Stopwatch &instance();

        /**
         * get elapsed time
         * @return elapsed time since last clock startup/restart
         */
        double getElapsedTime();

        /**
         * restart clock and get elapsed time since last clock reset
         * @return elapsed time since last clock reset
         */
        double restart();

    };
}


#endif //SPACEINVADERS_STOPWATCH_H
