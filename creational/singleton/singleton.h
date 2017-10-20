//
// Created by Simon on 2017/9/29.
//

#ifndef DESIGN_PATTERN_SINGLETON_H
#define DESIGN_PATTERN_SINGLETON_H

#include "../../main.h"

namespace singleton {
    class Number {
    public:
        static Number *instance();
        static void setType(int type);
        virtual void setValue(int v);
        virtual int getValue();

    protected:
        int value = 1;
        Number() = default;

    private:
        static int type;
        static Number *inst;
    };

    class NumberPlusOne : public Number {
    public:
        friend class Number;
        void setValue(int v) override;

    protected:
        NumberPlusOne() = default;
    };

    class NumberPlusTwo : public Number {
    public:
        friend class Number;
        void setValue(int v) override;

    protected:
        NumberPlusTwo() = default;
    };
}

#endif //DESIGN_PATTERN_SINGLETON_H
