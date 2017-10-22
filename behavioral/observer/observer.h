//
// Created by Simon on 2017/10/22.
//

#ifndef DESIGN_PATTERN_OBSERVER_H
#define DESIGN_PATTERN_OBSERVER_H

#include "../../main.h"

namespace observer {

    class Observer;

    class Subject {
    public:
        void attach(Observer *obs);
        void setValue(int val);
        int getValue();
        void notify();

    private:
        std::vector<Observer *> views;
        int value;
    };

    class Observer {
    public:
        Observer(Subject *mod, int d);
        virtual void update() = 0;

    protected:
        Subject* getSubject();
        int getDivisor();

    private:
        Subject *model;
        int div;
    };

    class DivObserver : public Observer {
    public:
        DivObserver(Subject *mod, int d);
        void update() override ;
    };

    class ModObserver : public Observer {
    public:
        ModObserver(Subject *mod, int d);
        void update() override ;
    };

}

#endif //DESIGN_PATTERN_OBSERVER_H
