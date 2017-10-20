//
// Created by Simon on 2017/10/17.
//

#include "builder.h"

using namespace builder;

DistributedWorkPackage::DistributedWorkPackage(std::string type) {
    desc = "Distributed Work Package for: "+std::move(type);
}

void DistributedWorkPackage::setFile(std::string f, std::string v) {
    temp = "\nFile(" + std::move(f) + "): " + std::move(v);
    desc += temp;
}

void DistributedWorkPackage::setQueue(std::string f, std::string v) {
    temp = "\nQueue(" + std::move(f) + "): " + std::move(v);
    desc += temp;
}

void DistributedWorkPackage::setPathway(std::string f, std::string v) {
    temp = "\nPathway(" + std::move(f) + "): " + std::move(v);
    desc += temp;
}

const std::string DistributedWorkPackage::getState() {
    return desc;
}

DistributedWorkPackage* Builder::getResult() {
    return result;
}

UnixBuilder::UnixBuilder() {
    result = new DistributedWorkPackage("unix");
}

void UnixBuilder::configureFile(std::string file) {
    result->setFile("flatFile", file);
}

void UnixBuilder::configureQueue(std::string queue) {
    result->setQueue("FIFO", queue);
}

void UnixBuilder::configurePathway(std::string type) {
    result->setPathway("thread", type);
}

VmsBuilder::VmsBuilder() {
    result = new DistributedWorkPackage("vms");
}

void VmsBuilder::configureFile(std::string file) {
    result->setFile("ISAM", file);
}

void VmsBuilder::configureQueue(std::string queue) {
    result->setQueue("priority", queue);
}

void VmsBuilder::configurePathway(std::string type) {
    result->setPathway("LWP", type);
}

void Reader::setBuilder(Builder *b) {
    bb = b;
}

void Reader::construct(std::vector<PersistenceAttribute> vp) {
    for (auto a : vp) {
        if (a.type == PersistenceType::File) {
            bb->configureFile(a.value);
        } else if (a.type == PersistenceType::Queue) {
            bb->configureQueue(a.value);
        } else if (a.type == PersistenceType::Pathway) {
            bb->configurePathway(a.value);
        }
    }
}