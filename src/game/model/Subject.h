//
// Created by Arno Troch on 18/11/2019.
//

#ifndef SPACEINVADERS_SUBJECT_H
#define SPACEINVADERS_SUBJECT_H

#include "../view/Observer.h"
#include <vector>
#include <memory>

/**
 * Class used in "Observer pattern"
 *
 * This class is used for implementing the "Observer pattern". Any concrete classes inheriting from this
 * class will become a subject, which will be observed by one or more observers (classes inheriting from
 * the Object class). A subject sends notifications to all of its observers when something interesting
 * happens.
 */
class Subject {
protected:
    std::vector<Observer::Ptr> observers;

public:
    /**
     * default constructor
     */
    Subject() = default;

    /**
     * default destructor
     */
    ~Subject() = default;

    const std::vector<Observer::Ptr> &getObservers() const;

    /**
     * add Observer object to list of observers
     *
     * @param observer Observer object to be added
     */
    void addObserver(const Observer::Ptr &observer);

    /**
     * remove Observer object from list of observers
     *
     * @param observer Observer object to be removed
     */
    void removeObserver(const Observer::Ptr &observer);

    /**
     * notify all observers that something happened
     */
    virtual void notify() const;

};


#endif //SPACEINVADERS_SUBJECT_H
