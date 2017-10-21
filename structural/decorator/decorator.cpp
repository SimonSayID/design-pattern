//
// Created by Simon on 2017/10/20.
//

#include "decorator.h"

using namespace decorator;

TextField::TextField(int w, int h) {
    width = w;
    height = h;
}

void TextField::draw() {
    std::cout << "TextField: "
              << width << ", " << height << "\n";
}

Decorator::Decorator(Widget *w) {
    widget = w;
}

void Decorator::draw() {
    widget->draw();
}

BorderDecorator::BorderDecorator(Widget *w) : Decorator(w) {

}

void BorderDecorator::draw() {
    Decorator::draw();
    std::cout << " BorderDecorator" << "\n";
}

ScrollDecorator::ScrollDecorator(Widget *w) : Decorator(w) {

}

void ScrollDecorator::draw() {
    Decorator::draw();
    std::cout << " ScrollDecorator" << "\n";
}