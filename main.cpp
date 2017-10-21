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
    adapter_test();
    bridge_test();
    composite_test();
    decorator_test();
    facade_test();
    flyweight_test();
    proxy_test();
    std::cout << "test done" << std::endl;
    return 0;
}