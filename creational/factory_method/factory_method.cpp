//
// Created by Simon on 2017/10/18.
//

#include "factory_method.h"

using namespace factory_method;

Document::Document(int file) {
    name = file;
}

int Document::getName() {
    return name;
}

MyDocument::MyDocument(int d) : Document(d) {

}

void MyDocument::open() {
    std::cout << "MyDocument open()" << std::endl;
}

void MyDocument::close() {
    std::cout << "MyDocument close()" << std::endl;
}

Application::Application() : index(0) {
    std::cout << "Application ctor" << std::endl;
}

void Application::new_Application(int file) {
    std::cout << "Application new_Application()" << std::endl;
    vd.push_back(create_Document(file));
    vd[index++]->open();
}

void Application::open_Application() {

}

void Application::report_Documents() {
    std::cout << "Application report_Applications()" << std::endl;
    for (int i = 0; i < index; ++i) {
        std::cout << " " << vd[i]->getName() << std::endl;
    }
}

MyApplication::MyApplication() {
    std::cout << "MyApplication ctor" << std::endl;

}

Document* MyApplication::create_Document(int file) {
    std::cout << "MyApplication create_Document()" << std::endl;
    return new MyDocument(file);
}