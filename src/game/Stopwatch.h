//
// Created by Arno Troch on 19/11/2019.
//

#ifndef SPACEINVADERS_STOPWATCH_H
#define SPACEINVADERS_STOPWATCH_H

#include <memory>
#include <chrono>

typedef std::chrono::system_clock::time_point Time;

class Stopwatch {
private:
    Stopwatch();

    Time last_recorded_time;

public:
    virtual ~Stopwatch() = default;

    static Stopwatch &instance();

    double getElapsedTime();

    double restart();

};


#endif //SPACEINVADERS_STOPWATCH_H
