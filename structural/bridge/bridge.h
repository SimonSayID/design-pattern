//
// Created by Simon on 2017/10/20.
//

#ifndef DESIGN_PATTERN_BRIDGE_H
#define DESIGN_PATTERN_BRIDGE_H

#include "../../main.h"

namespace bridge {

    class TimeImpl {
    public:
        TimeImpl(int hr, int min);
        virtual void tell();

    protected:
        int _hr, _min;
    };

    class CivilianTimeImpl : public TimeImpl {
    public:
        CivilianTimeImpl(int hr, int min, int pm);
        void tell() override ;

    protected:
        std::string MF;
    };

    class ZuluTimeImpl : public TimeImpl {
    public:
        ZuluTimeImpl(int hr, int min, int zone);
        void tell() override ;

    protected:
        std::string _zone;
    };

    class Time {
    public:
        Time() = default;
        Time(int hr, int min);
        virtual void tell();

    protected:
        TimeImpl *impl = nullptr;
    };

    class CivilianTime : public Time {
    public:
        CivilianTime(int hr, int min, int pm);
    };

    class ZuluTime: public Time {
    public:
        ZuluTime(int hr, int min, int zone);
    };
}

#endif //DESIGN_PATTERN_BRIDGE_H
