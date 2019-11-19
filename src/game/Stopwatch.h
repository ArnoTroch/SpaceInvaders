//
// Created by Arno Troch on 19/11/2019.
//

#ifndef SPACEINVADERS_STOPWATCH_H
#define SPACEINVADERS_STOPWATCH_H

#include <memory>

class Stopwatch {
private:
    Stopwatch() = default;

public:
    static std::weak_ptr<Stopwatch> getInstance();

    void start();

    void stop();

};


#endif //SPACEINVADERS_STOPWATCH_H
