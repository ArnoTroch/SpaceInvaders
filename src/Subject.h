//
// Created by Arno Troch on 18/11/2019.
//

#ifndef SPACEINVADERS_SUBJECT_H
#define SPACEINVADERS_SUBJECT_H

#include "Observer.h"
#include <vector>
#include <memory>

using namespace std;

/**
 * Class used in "Observer pattern"
 *
 * This class is used for implementing the "Observer pattern". Any concrete classes inheriting from this
 * class will become a subject, which will be observed by one or more observers (classes inheriting from
 * the Object class). A subject sends notifications to all of its observers when something interesting
 * happens.
 */
class Subject {
private:
    vector<shared_ptr<Observer>> observers;

public:
    /**
     * default constructor
     */
    Subject() = default;

    /**
     * default destructor
     */
    ~Subject() = default;

    /**
     * add Observer object to list of observers.
     *
     * @param observer Observer object to be added
     */
    void addObserver(const shared_ptr<Observer> &observer);

    /**
     * remove Observer object from list of observers.
     *
     * @param observer Observer object to be removed
     */
    void removeObserver(const shared_ptr<Observer> &observer);

};


#endif //SPACEINVADERS_SUBJECT_H
