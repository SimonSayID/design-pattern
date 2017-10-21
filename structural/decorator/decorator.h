//
// Created by Simon on 2017/10/20.
//

#ifndef DESIGN_PATTERN_DECORATOR_H
#define DESIGN_PATTERN_DECORATOR_H

#include "../../main.h"

namespace decorator {

    class Widget {
    public:
        virtual void draw() = 0;
    };

    class TextField : public Widget {
    public:
        TextField(int w, int h);
        void draw() override;

    private:
        int width;
        int height;
    };

    class Decorator : public Widget {
    public:
        Decorator(Widget *w);
        void draw() override ;

    private:
        Widget *widget;
    };

    class BorderDecorator : public Decorator {
    public:
        BorderDecorator(Widget *w);
        void draw() override ;
    };

    class ScrollDecorator : public Decorator {
    public:
        ScrollDecorator(Widget *w);
        void draw() override ;
    };

}

#endif //DESIGN_PATTERN_DECORATOR_H
