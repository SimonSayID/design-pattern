//
// Created by Simon on 2017/10/21.
//

#ifndef DESIGN_PATTERN_PROXY_H
#define DESIGN_PATTERN_PROXY_H

#include "../../main.h"

namespace proxy {

    class Person {
    public:
        Person();
        std::string getName();

    private:
        std::string name;
        static const char* list[];
        static int next;
    };


    class PettyCashProtected {
    public:
        PettyCashProtected();
        bool withdraw(int amount);
        int getBalance();

    private:
        int balance;
    };

    class PettyCash {
    public:
        bool withdraw(Person &person, int amount);
        int getBalance();

    private:
        PettyCashProtected realThing;
    };

}

#endif //DESIGN_PATTERN_PROXY_H
