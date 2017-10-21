//
// Created by Simon on 2017/10/21.
//

#include "facade.h"

using namespace facade;

void MisDepartment::submitNetworkRequest() {
    _state = 0;
}

bool MisDepartment::checkOnStatus() {
    _state++;
    if (_state == Complete) {
        return true;
    }
    return false;
}

void ElectricianUnion::submitNetworkRequest() {
    _state = 0;
}

bool ElectricianUnion::checkOnStatus() {
    _state++;
    if (_state == Complete) {
        return true;
    }
    return false;
}

void FacilitiesDepartment::submitNetworkRequest() {
    _state = 0;
}

bool FacilitiesDepartment::checkOnStatus() {
    _state++;
    if (_state == Complete) {
        return true;
    }
    return false;
}

FacilitiesFacade::FacilitiesFacade() {
    _count = 0;
}

void FacilitiesFacade::submitNetworkRequest() {
    _state = 0;
}

bool FacilitiesFacade::checkOnStatus() {
    _count++;
    if (_state == Received) {
        _state++;
        _engineer.submitNetworkRequest();
        std::cout << "submitted to Facilities - " << _count
                  << " phone calls so far" << std::endl;
    } else if (_state == SubmitToEngineer) {
        if (_engineer.checkOnStatus()) {
            _state++;
            _electrician.submitNetworkRequest();
            std::cout << "submitted to Electrician - " << _count
                      << " phone calls so far" << std::endl;
        }
    } else if (_state == SubmitToElectrician) {
        if (_electrician.checkOnStatus()) {
            _state++;
            _technician.submitNetworkRequest();
            std::cout << "submitted to MIS - " << _count
                      << " phone calls so far" << std::endl;
        }
    } else if (_state == SubmitToTechnician) {
        if (_technician.checkOnStatus()) {
            return true;
        }
    }
    return false;
}

int FacilitiesFacade::getNumberOfCalls() {
    return _count;
}