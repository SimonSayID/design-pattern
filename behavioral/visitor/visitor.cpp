//
// Created by Simon on 2017/10/22.
//

#include "visitor.h"

using namespace visitor;

void This::accept(Visitor &v) {
    v.visit(this);
}

std::string This::getThis() {
    return "this";
}

void That::accept(Visitor &v) {
    v.visit(this);
}

std::string That::getThat() {
    return "that";
}

void TheOther::accept(Visitor &v) {
    v.visit(this);
}

std::string TheOther::getTheOther() {
    return "theOther";
}

void UpVisitor::visit(This *e) {
    std::cout << "do up on " + e->getThis() << "\n";
}

void UpVisitor::visit(That *e) {
    std::cout << "do up on " + e->getThat() << "\n";
}

void UpVisitor::visit(TheOther *e) {
    std::cout << "do up on " + e->getTheOther() << "\n";
}

void DownVisitor::visit(This *e) {
    std::cout << "do down on " + e->getThis() << "\n";
}
void DownVisitor::visit(That *e) {
    std::cout << "do down on " + e->getThat() << "\n";
}

void DownVisitor::visit(TheOther *e) {
    std::cout << "do down on " + e->getTheOther() << "\n";
}