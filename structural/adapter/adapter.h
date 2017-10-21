//
// Created by Simon on 2017/10/20.
//

#ifndef DESIGN_PATTERN_ADAPTER_H
#define DESIGN_PATTERN_ADAPTER_H

#include "../../main.h"

namespace adapter {

    class Rectangle {
    public:
        virtual void draw() = 0;
    };

    class LegacyRectangle {
    public:
        LegacyRectangle(int x1, int y1, int x2, int y2);
        void oldDraw();

    private:
        int _x1;
        int _y1;
        int _x2;
        int _y2;
    };

    class RectangleAdapter : public Rectangle, private LegacyRectangle {
    public:
        RectangleAdapter(int x, int y, int w, int h);
        void draw() override ;
    };

}

#endif //DESIGN_PATTERN_ADAPTER_H
