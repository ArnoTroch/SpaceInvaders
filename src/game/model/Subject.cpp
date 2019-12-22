//
// Created by Arno Troch on 18/11/2019.
//

#include "Subject.h"

const std::vector<game::Observer::Ptr> &game::Subject::getObservers() const {
    return observers;
}

void game::Subject::addObserver(const Observer::Ptr &observer) {
    observers.push_back(observer);
}

void game::Subject::removeObserver(const Observer::Ptr &observer) {
    for (unsigned long i = 0; i < observers.size(); ++i) {
        if (observers[i] == observer) {
            observers.erase(observers.begin() + i);
            return;
        }
    }
}

void game::Subject::notify() const {
    for (const Observer::Ptr &obs: observers) {
        obs->onNotify();
    }
}
