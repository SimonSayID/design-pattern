//
// Created by Simon on 2017/10/20.
//

#include "adapter.h"

using namespace adapter;

LegacyRectangle::LegacyRectangle(int x1, int y1, int x2, int y2) {
    _x1 = x1;
    _y1 = y1;
    _x2 = x2;
    _y2 = y2;
    std::cout << "LegacyRectangle create(): "
              << _x1 << "," << _y1 << ","
              << _x2 << "," << _y2 << std::endl;
}

void LegacyRectangle::oldDraw() {
    std::cout << "LegacyRectangle oldDraw(): "
              << _x1 << "," << _y1 << ","
              << _x2 << "," << _y2 << std::endl;
}

RectangleAdapter::RectangleAdapter(int x, int y, int w, int h) : LegacyRectangle(x, y, w, h) {
    std::cout << "RectangleAdapter create(): "
              << "(" << x << "," << y << "),"
              << "width:" << w << ",height:" << w << std::endl;
}

void RectangleAdapter::draw() {
    std::cout << "RectangleAdapter draw()" << std::endl;
    oldDraw();
}