//
// Created by Arno Troch on 19/11/2019.
//

#ifndef SPACEINVADERS_STOPWATCH_H
#define SPACEINVADERS_STOPWATCH_H

#include <memory>
#include <chrono>

typedef std::chrono::system_clock::time_point Time;


/**
 * Singleton class used for measuring time differences between two timestamps.
 *
 */
class Stopwatch {
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


#endif //SPACEINVADERS_STOPWATCH_H
