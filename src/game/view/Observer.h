//
// Created by Arno Troch on 18/11/2019.
//

#ifndef SPACEINVADERS_OBSERVER_H
#define SPACEINVADERS_OBSERVER_H

#include <memory>
#include "../../entity/Entity.h"

namespace game {
    /**
     * Abstract class used in "Observer pattern"
     *
     * This class is used for implementing the "Observer pattern". Any concrete classes inheriting from
     * this class will become an observer. It will observe an object inheriting from the Subject class.
     */
    class Observer {
    public:
        /**
         * shared_ptr to Observer is defined as game::Observer::Ptr, in order to
         * simplify commonly used types.
         */
        using Ptr = std::shared_ptr<Observer>;

        /**
         * create an Observer
         */
        Observer() = default;

        /**
         * Default destructor
         */
        virtual ~Observer() = default;

        /**
         * Handle events when right notification is invoked by Subject.
         */
        virtual void onNotify() = 0;
    };
}


#endif //SPACEINVADERS_OBSERVER_H
