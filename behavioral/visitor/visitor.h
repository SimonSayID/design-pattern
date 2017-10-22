//
// Created by Simon on 2017/10/22.
//

#ifndef DESIGN_PATTERN_VISITOR_H
#define DESIGN_PATTERN_VISITOR_H

#include "../../main.h"

namespace visitor {

    class Visitor;

    class Element {
    public:
        virtual void accept(Visitor &v) = 0;
    };

    class This : public Element {
    public:
        void accept(Visitor &v) override ;
        std::string getThis();
    };

    class That : public Element {
    public:
        void accept(Visitor &v) override ;
        std::string getThat();
    };

    class TheOther : public Element {
    public:
        void accept(Visitor &v) override ;
        std::string getTheOther();
    };

    class Visitor {
    public:
        virtual void visit(This *e) = 0;
        virtual void visit(That *e) = 0;
        virtual void visit(TheOther *e) = 0;
    };

    class UpVisitor : public Visitor {
        void visit(This *e) override;
        void visit(That *e) override;
        void visit(TheOther *e) override;
    };

    class DownVisitor : public Visitor {
        void visit(This *e) override;
        void visit(That *e) override;
        void visit(TheOther *e) override;
    };
}
#endif //DESIGN_PATTERN_VISITOR_H
