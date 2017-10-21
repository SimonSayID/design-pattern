//
// Created by Simon on 2017/10/20.
//

#include "composite.h"

using namespace composite;

Primitive::Primitive(int val) {
    value = val;
}

void Primitive::traverse() {
    std::cout << value << " ";
}

Composite::Composite(int val) {
    value = val;
}

void Composite::add(Component *component) {
    children.push_back(component);
}

void Composite::traverse() {
    std::cout << value << " ";
    for (auto c : children) {
        c->traverse();
    }
}

Row::Row(int val) : Composite(val) {

}

void Row::traverse() {
    std::cout << "Row";
    Composite::traverse();
}

Column::Column(int val) : Composite(val) {

}

void Column::traverse() {
    std::cout << "Col";
    Composite::traverse();
}