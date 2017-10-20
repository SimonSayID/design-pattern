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
        "*.h"
        "*.cpp"
)

add_executable(design-pattern ${SOURCE})