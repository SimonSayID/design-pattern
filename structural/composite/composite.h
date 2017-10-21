//
// Created by Simon on 2017/10/20.
//

#ifndef DESIGN_PATTERN_COMPOSITE_H
#define DESIGN_PATTERN_COMPOSITE_H

#include "../../main.h"

namespace composite {

    class Component {
    public:
        virtual void traverse() = 0;
    };

    class Primitive : public Component {
    public:
        explicit Primitive(int val);
        void traverse() override ;

    private:
        int value;
    };

    class Composite : public Component {
    public:
        explicit Composite(int val);
        void traverse() override ;
        void add(Component *component);

    private:
        int value;
        std::vector<Component*> children;
    };

    class Row : public Composite {
    public:
        explicit Row(int val);
        void traverse() override ;
    };

    class Column : public Composite {
    public:
        explicit Column(int val);
        void traverse() override ;
    };
};


#endif //DESIGN_PATTERN_COMPOSITE_H
