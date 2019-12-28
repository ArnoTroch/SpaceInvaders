//
// Created by Arno Troch on 18/11/2019.
//

#ifndef SPACEINVADERS_SUBJECT_H
#define SPACEINVADERS_SUBJECT_H

#include "../view/Observer.h"
#include <vector>
#include <memory>

namespace game {
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
        /**
         * shared_ptr to Subject is defined as game::Subject::Ptr, in order to
         * simplify commonly used types.
         */
        std::vector<Observer::Ptr> observers;

    public:
        /**
         * create a Subject
         */
        Subject() = default;

        /**
         * default destructor
         */
        ~Subject() = default;

        /**
         * get observers
         * @return observers of Subject
         */
        [[nodiscard]] const std::vector<Observer::Ptr> &getObservers() const;

        /**
         * add new Observer
         * @param observer new observer for Subject
         */
        void addObserver(const Observer::Ptr &observer);

        /**
         * remove certain Observer
         * @param observer observer to be removed for Subject
         */
        void removeObserver(const Observer::Ptr &observer);

        /**
         * notify the observers when something interesting happens
         */
        virtual void notify() const;

    };
}


#endif //SPACEINVADERS_SUBJECT_H
