//
// Created by Simon on 2017/9/20.
//

#include "main.h"
#include "test.h"

int main() {
    abstract_factory_test();
    builder_test();
    factory_method_test();
    prototype_test();
    singleton_test();
    std::cout << "done" << std::endl;
    return 0;
}