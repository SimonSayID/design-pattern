//
// Created by Simon on 2017/10/20.
//

#include "adapter/adapter.h"
#include "bridge/bridge.h"
#include "composite/composite.h"
#include "decorator/decorator.h"
#include "facade/facade.h"
#include "flyweight/flyweight.h"
#include "proxy/proxy.h"

void adapter_test() {

    using namespace adapter;

    Rectangle *r = new RectangleAdapter(120, 200, 60, 40);
    r->draw();

}

void bridge_test() {

    using namespace bridge;

    Time *times[4];
    times[0] = new Time(14, 30);
    times[1] = new CivilianTime(2, 30, 1);
    times[2] = new ZuluTime(14, 30, 5);
    times[3] = new ZuluTime(14, 30, 6);
    for (auto i : times) {
        i->tell();
    }

}

void composite_test() {

    using namespace composite;

    Row first(1);
    Column second(2);
    Column third(3);
    Row fourth(4);
    Row fifth(5);
    first.add(&second);
    first.add(&third);
    third.add(&fourth);
    third.add(&fifth);
    auto p1 = Primitive(6);
    first.add(&p1);
    auto p2 = Primitive(7);
    second.add(&p2);
    auto p3 = Primitive(8);
    third.add(&p3);
    auto p4 = Primitive(9);
    fourth.add(&p4);
    auto p5 = Primitive(10);
    fifth.add(&p5);
    first.traverse();
    std::cout << std::endl;

}

void decorator_test() {

    using namespace decorator;

    Widget *w = new BorderDecorator(
            new BorderDecorator(
                    new ScrollDecorator(
                            new TextField(80, 24)
                    )
            )
    );

    w->draw();
}

void facade_test() {

    using namespace facade;

    FacilitiesFacade facilitiesFacade;

    facilitiesFacade.submitNetworkRequest();
    while (!facilitiesFacade.checkOnStatus());
    std::cout << "job completed after only "
              << facilitiesFacade.getNumberOfCalls() << " phone calls" << std::endl;
}

void flyweight_test() {

    using namespace flyweight;

    DialogBox *dialogBox[2];
    dialogBox[0] = new FileSelection(
            FlyweightFactory::getIcon("go"),
            FlyweightFactory::getIcon("stop"),
            FlyweightFactory::getIcon("select")
    );
    dialogBox[1] = new CommitTransaction(
            FlyweightFactory::getIcon("select"),
            FlyweightFactory::getIcon("stop"),
            FlyweightFactory::getIcon("undo")
    );

    for (auto i : dialogBox) {
        i->draw();
    }

    FlyweightFactory::reportTheIcons();
}

void proxy_test() {

    using namespace proxy;

    PettyCash pettyCash;
    Person people[4];
    for (int i = 0, amount = 100; i < 4; ++i, amount += 100) {
        if (!pettyCash.withdraw(people[i], amount)) {
            std::cout << "No money for " << people[i].getName() << "\n";
        } else {
            std::cout << amount << " dollars for " << people[i].getName() << "\n";
        }
    }
    std::cout << "Remaining balance is " << pettyCash.getBalance() << "\n";
}