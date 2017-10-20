//
// Created by Simon on 2017/9/20.
//

#ifndef DESIGN_PATTERN_ABSTRACT_FACTORY_H
#define DESIGN_PATTERN_ABSTRACT_FACTORY_H

#include "../../main.h"

namespace abstract_factory {

    class Shape {
    public:
        Shape();
        virtual std::string str() = 0;
    protected:
        int id;
        static int total;
    };

    class Circle : public Shape {
    public:
        std::string str() override ;
    };

    class Square : public Shape {
    public:
        std::string str() override ;
    };

    class Ellipse : public Shape {
    public:
        std::string str() override ;
    };

    class Rectangle : public Shape {
    public:
        std::string str() override ;
    };

    class Factory {
    public:
        virtual Shape* createFirstInstance() = 0;
        virtual Shape* createSecondInstance() = 0;
    };

    class SimpleShapeFactory : public Factory {
    public:
        Shape* createFirstInstance() override ;
        Shape* createSecondInstance() override ;
    };

    class RobustShapeFactory : public Factory {
    public:
        Shape* createFirstInstance() override ;
        Shape* createSecondInstance() override ;
    };
}

#endif //DESIGN_PATTERN_ABSTRACT_FACTORY_H
