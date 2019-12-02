//
// Created by Arno Troch on 25/11/2019.
//

#include "Transformation.h"

Transformation &Transformation::instance() {
    static std::unique_ptr<Transformation> sw(new Transformation());
    return *sw;
}
