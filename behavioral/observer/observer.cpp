//
// Created by Simon on 2017/10/22.
//

#include "observer.h"

using namespace observer;

void Subject::attach(Observer *obs) {
    views.push_back(obs);
}

void Subject::setValue(int val) {
    value = val;
    notify();
}

int Subject::getValue() {
    return value;
}

void Subject::notify() {
    size_t len = views.size();
    for (int i = 0; i < len; ++i) {
        views[i]->update();
    }
}

Observer::Observer(Subject *mod, int d) {
    model = mod;
    div = d;
    model->attach(this);
}

Subject* Observer::getSubject() {
    return model;
}

int Observer::getDivisor() {
    return div;
}

DivObserver::DivObserver(Subject *mod, int d)
        : Observer(mod, d) {

}

void DivObserver::update() {
    int v = getSubject()->getValue();
    int d = getDivisor();
    std::cout << v << " div " << d << " is " << v / d << "\n";
}

ModObserver::ModObserver(Subject *mod, int d)
        : Observer(mod, d) {

}

void ModObserver::update() {
    int v = getSubject()->getValue();
    int d = getDivisor();
    std::cout << v << " mod " << d << " is " << v % d << "\n";
}