cmake_minimum_required(VERSION 3.8)
project(design-pattern)

set(CMAKE_CXX_STANDARD 17)

file(
        GLOB SOURCE
        "behavioral/*.h"
        "behavioral/*.cpp"
        "creational/*.h"
        "creational/*.cpp"
        "creational/abstract_factory/*.h"
        "creational/abstract_factory/*.cpp"
        "creational/builder/*.h"
        "creational/builder/*.cpp"
        "creational/factory_method/*.h"
        "creational/factory_method/*.cpp"
        "creational/prototype/*.h"
        "creational/prototype/*.cpp"
        "creational/singleton/*.h"
        "creational/singleton/*.cpp"
        "structural/*.h"
        "structural/*.cpp"
        "structural/adapter/*.h"
        "structural/adapter/*.cpp"
        "structural/bridge/*.h"
        "structural/bridge/*.cpp"
        "structural/composite/*.h"
        "structural/composite/*.cpp"
        "structural/decorator/*.h"
        "structural/decorator/*.cpp"
        "structural/facade/*.h"
        "structural/facade/*.cpp"
        "structural/flyweight/*.h"
        "structural/flyweight/*.cpp"
        "structural/proxy/*.h"
        "structural/proxy/*.cpp"
        "*.h"
        "*.cpp"
)

add_executable(design-pattern ${SOURCE})