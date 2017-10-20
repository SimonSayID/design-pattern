//
// Created by Simon on 2017/9/29.
//

#include "singleton.h"

using namespace singleton;

int Number::type = 0;
Number *Number::inst = nullptr;

Number* Number::instance() {
    if (!inst) {
        if (type == 1) {
            inst = new NumberPlusOne();
        } else if (type == 2) {
            inst = new NumberPlusTwo();
        } else {
            inst = new Number();
        }
    }
    return inst;
}

void Number::setType(int t) {
    type = t;
    delete inst;
    inst = nullptr;
}

void Number::setValue(int v) {
    value = v;
}

int Number::getValue() {
    return value;
}

void NumberPlusOne::setValue(int v) {
    value = v + 1;
}

void NumberPlusTwo::setValue(int v) {
    value = v + 2;
}