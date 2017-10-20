//
// Created by Simon on 2017/9/29.
//

#include "abstract_factory/abstract_factory.h"
#include "builder/builder.h"
#include "factory_method/factory_method.h"
#include "prototype/prototype.h"
#include "singleton/singleton.h"

void abstract_factory_test() {

    using namespace abstract_factory;

    Factory *f = new SimpleShapeFactory();

    Shape *a[2];

    a[0] = f->createFirstInstance();
    a[1] = f->createSecondInstance();
    assert((a[0])->str() == "Circle 0");
    assert((a[1])->str() == "Square 1");

    delete f;
    delete a[0];
    delete a[1];

    f = new RobustShapeFactory();
    a[0] = f->createFirstInstance();
    a[1] = f->createSecondInstance();

    assert((a[0])->str() == "Ellipse 2");
    assert((a[1])->str() == "Rectangle 3");

    delete f;
    delete a[0];
    delete a[1];
}

void builder_test() {

    using namespace builder;

    PersistenceAttribute p1{PersistenceType::File, "state.dat"};
    PersistenceAttribute p2{PersistenceType::File, "config.sys"};
    PersistenceAttribute p3{PersistenceType::Queue, "compute"};
    PersistenceAttribute p4{PersistenceType::Queue, "log"};
    PersistenceAttribute p5{PersistenceType::Pathway, "authentication"};
    PersistenceAttribute p6{PersistenceType::Pathway, "error processing"};

    std::vector<PersistenceAttribute> vp;
    vp.push_back(p1);
    vp.push_back(p2);
    vp.push_back(p3);
    vp.push_back(p4);
    vp.push_back(p5);
    vp.push_back(p6);

    UnixBuilder ub;
    VmsBuilder vb;
    Reader r = Reader();

    r.setBuilder(&ub);
    r.construct(vp);

    std::istringstream data;
    data.str(ub.getResult()->getState());
    std::vector<std::string> vs;
    std::string s;
    while (std::getline(data, s)) {
        vs.push_back(s);
    }
    assert(vs[0] == "Distributed Work Package for: unix");
    assert(vs[1] == "File(flatFile): state.dat");
    assert(vs[2] == "File(flatFile): config.sys");
    assert(vs[3] == "Queue(FIFO): compute");
    assert(vs[4] == "Queue(FIFO): log");
    assert(vs[5] == "Pathway(thread): authentication");
    assert(vs[6] == "Pathway(thread): error processing");

    r.setBuilder(&vb);
    r.construct(vp);
    data.str(vb.getResult()->getState());
    data.clear();
    vs.clear();
    while (std::getline(data, s)) {
        vs.push_back(s);
    }
    assert(vs[0] == "Distributed Work Package for: vms");
    assert(vs[1] == "File(ISAM): state.dat");
    assert(vs[2] == "File(ISAM): config.sys");
    assert(vs[3] == "Queue(priority): compute");
    assert(vs[4] == "Queue(priority): log");
    assert(vs[5] == "Pathway(LWP): authentication");
    assert(vs[6] == "Pathway(LWP): error processing");
}

void factory_method_test() {

    using namespace factory_method;

    MyApplication myApplication;
    myApplication.new_Application(11);
    myApplication.new_Application(22);
    myApplication.new_Application(33);
    myApplication.report_Documents();

}

void prototype_test() {

    using namespace prototype;

    std::vector<imageType> vt{ imageType::LSAT, imageType::LSAT, imageType::LSAT,
                               imageType::SPOT, imageType::LSAT, imageType::SPOT,
                               imageType::SPOT, imageType::LSAT};

    size_t size{vt.size()};
    std::vector<Image *> vm(size);
    for (int i = 0; i < size; ++i) {
        vm[i] = Image::findAndClone(vt[i]);
    }

    for (int j = 0; j < size; ++j) {
        vm[j]->draw();
    }

    for (int k = 0; k < size; ++k) {
        delete vm[k];
    }
}

void singleton_test() {

    using namespace singleton;

    auto a = Number::instance();
    assert(a->getValue() == 1);

    a->setValue(10);
    assert(a->getValue() == 10);

    auto d1 = &(*a);
    a->setType(1);
    auto d2 = &(*a);
    assert(d1 == d2);

    a = NumberPlusOne::instance();
    auto b = NumberPlusOne::instance();
    assert(a->getValue() == 1);
    assert(b->getValue() == 1);
    assert(&(*a) == &(*b));

    b->setValue(10);
    assert(a->getValue() == 11);
    assert(b->getValue() == 11);

    b->setType(2);
    a = Number::instance();
    b = NumberPlusOne::instance();
    auto c = NumberPlusTwo::instance();
    assert(a->getValue() == 1);
    assert(b->getValue() == 1);
    assert(c->getValue() == 1);

    c->setValue(10);
    assert(a->getValue() == 12);
    assert(b->getValue() == 12);
    assert(c->getValue() == 12);
    assert(&(*a) == &(*b));
    assert(&(*b) == &(*c));

    delete c;
}
