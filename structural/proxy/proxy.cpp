//
// Created by Simon on 2017/10/21.
//

#include "proxy.h"

using namespace proxy;

const char* Person::list[] = {"Tom", "Ben", "Harry", "Ken"};
int Person::next = 0;

Person::Person() {
    name = list[next++];
}

std::string Person::getName() {
    return name;
}

PettyCashProtected::PettyCashProtected() {
    balance = 500;
}

bool PettyCashProtected::withdraw(int amount) {
    if (amount > balance) {
        return false;
    }
    balance -= amount;
    return true;
}

int PettyCashProtected::getBalance() {
    return balance;
}

bool PettyCash::withdraw(Person &person, int amount) {
    if (person.getName() == "Tom"
        || person.getName() == "Harry"
        || person.getName() == "Ken") {
        return realThing.withdraw(amount);
    } else {
        return false;
    };
}

int PettyCash::getBalance() {
    return realThing.getBalance();
}
