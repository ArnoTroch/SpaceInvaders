//
// Created by Arno Troch on 18/11/2019.
//

#include "Subject.h"

void Subject::addObserver(const shared_ptr<Observer> &observer) {
    observers.push_back(observer);
}

void Subject::removeObserver(const shared_ptr<Observer> &observer) {
    for (unsigned long i = 0; i < observers.size(); ++i) {
        if (observers[i] == observer) {
            observers.erase(observers.begin() + i);
            return;
        }
    }
}
