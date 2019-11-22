//
// Created by Arno Troch on 19/11/2019.
//

#include "Stopwatch.h"

Stopwatch::Stopwatch() {
    last_recorded_time = std::chrono::system_clock::now();
}

Stopwatch &Stopwatch::instance() {
    static std::unique_ptr<Stopwatch> sw(new Stopwatch());
    return *sw;
}

double Stopwatch::getElapsedTime() {
    Time now = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = now - last_recorded_time;
    return diff.count();
}

double Stopwatch::restart() {
    Time now = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = now - last_recorded_time;
    last_recorded_time = now;
    return diff.count();
}

