//
// Created by Simon on 2017/10/22.
//

#include "observer/observer.h"
#include "visitor/visitor.h"

void observer_test() {

    using namespace observer;

    Subject subject = Subject();
    DivObserver div1(&subject, 4);
    DivObserver div2(&subject, 3);
    ModObserver mod1(&subject, 3);
    subject.setValue(14);

}

void visitor_test() {

    using namespace visitor;

    Element *list[] = { new This, new That, new TheOther };
    UpVisitor upVisitor;
    DownVisitor downVisitor;
    for (int i = 0; i < 3; ++i) {
        list[i]->accept(upVisitor);
    }
    for (int i = 0; i < 3; ++i) {
        list[i]->accept(downVisitor);
    }
}