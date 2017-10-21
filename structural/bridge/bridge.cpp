//
// Created by Simon on 2017/10/20.
//

#include "bridge.h"

using namespace bridge;

TimeImpl::TimeImpl(int hr, int min) {
    _hr = hr;
    _min = min;
}

void TimeImpl::tell() {
    std::cout << "time is ";
    std::cout << _hr << ":" << _min << std::endl;
}

CivilianTimeImpl::CivilianTimeImpl(int hr, int min, int pm)
        : TimeImpl(hr, min) {
    if (pm) {
        MF = " PM";
    } else {
        MF = " AM";
    }
}

void CivilianTimeImpl::tell() {
    std::cout << "time is "
              << _hr << ":" << _min << MF << std::endl;
}

ZuluTimeImpl::ZuluTimeImpl(int hr, int min, int zone)
        : TimeImpl(hr, min) {
    if (zone == 5) {
        _zone = " Eastern Standard Time";
    } else if (zone == 6){
        _zone = " Central Standard Time";
    }
}

void ZuluTimeImpl::tell() {
    std::cout << "time is ";
    std::cout << _hr << ":" << _min << _zone << std::endl;
}

Time::Time(int hr, int min) {
    impl = new TimeImpl(hr, min);
}

void Time::tell() {
    impl->tell();
}

CivilianTime::CivilianTime(int hr, int min, int pm) {
    impl = new CivilianTimeImpl(hr, min, pm);
}

ZuluTime::ZuluTime(int hr, int min, int zone) {
    impl = new ZuluTimeImpl(hr, min, zone);
}