//
// Created by Simon on 2017/9/20.
//

#include "abstract_factory.h"

using namespace abstract_factory;

int Shape::total = 0;

Shape::Shape() {
    id = total++;
}

std::string Circle::str() {
    return "Circle "+std::to_string(id);
}

std::string Square::str() {
    return "Square "+std::to_string(id);
}

std::string Ellipse::str() {
    return "Ellipse "+std::to_string(id);
}

std::string Rectangle::str() {
    return "Rectangle "+std::to_string(id);
}

Shape* SimpleShapeFactory::createFirstInstance() {
    return new Circle;
}

Shape* SimpleShapeFactory::createSecondInstance() {
    return new Square;
}

Shape* RobustShapeFactory::createFirstInstance() {
    return new Ellipse;
}

Shape* RobustShapeFactory::createSecondInstance() {
    return new Rectangle;
}