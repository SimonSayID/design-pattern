//
// Created by Simon on 2017/10/21.
//

#include "flyweight.h"

using namespace flyweight;

int FlyweightFactory::_numIcons = 0;
Icon *FlyweightFactory::_icons[];

Icon::Icon(std::string fileName) {
    name = fileName;
    if (name == "go") {
        _width = 20;
        _height = 20;
    }
    if (name == "stop") {
        _width = 40;
        _height = 40;
    }
    if (name == "select") {
        _width = 60;
        _height = 60;
    }
    if (name == "undo") {
        _width = 30;
        _height = 30;
    }
}

void Icon::draw(int x, int y) {
    std::cout << " drawing " << name << ": upper left (" << x << "," << y
              << ") - lower right (" << x + _width << "," << y + _height << ")" << std::endl;
}

const std::string Icon::getName() {
    return name;
}

Icon* FlyweightFactory::getIcon(std::string name) {
    for (int i = 0; i < _numIcons; ++i) {
        if (name == _icons[i]->getName()) {
            return _icons[i];
        }
    }
    _icons[_numIcons] = new Icon(name);
    return _icons[_numIcons++];
}

void FlyweightFactory::reportTheIcons() {
    std::cout << "Active Flyweight: ";
    for (int i = 0; i < _numIcons; ++i) {
        std::cout << _icons[i]->getName() << " ";
    }
    std::cout << std::endl;
}

DialogBox::DialogBox(int x, int y, int incr)
        : _iconsOriginX(x), _iconsOriginY(y), _iconsIncrement(incr){

}

FileSelection::FileSelection(Icon *first, Icon *second, Icon *third)
        : DialogBox(100, 100, 100) {
    _icons[0] = first;
    _icons[1] = second;
    _icons[2] = third;
}

void FileSelection::draw() {
    std::cout << "drawing FileSelection:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        _icons[i]->draw(_iconsOriginX + (i * _iconsIncrement), _iconsOriginY);
    }
}

CommitTransaction::CommitTransaction(Icon *first, Icon *second, Icon *third)
        : DialogBox(150, 150, 150) {
    _icons[0] = first;
    _icons[1] = second;
    _icons[2] = third;
}

void CommitTransaction::draw() {
    std::cout << "drawing CommitTransaction:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        _icons[i]->draw(_iconsOriginX + (i * _iconsIncrement), _iconsOriginY);
    }
}