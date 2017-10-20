//
// Created by Simon on 2017/10/18.
//

#ifndef DESIGN_PATTERN_FACTORY_METHOD_H
#define DESIGN_PATTERN_FACTORY_METHOD_H

#include "../../main.h"

namespace factory_method {

    class Document {
    public:
        explicit Document(int file);
        virtual void open() = 0;
        virtual void close() = 0;
        int getName();

    private:
        int name;
    };

    class MyDocument : public Document {
    public:
        explicit MyDocument(int d);
        void open() override ;
        void close() override ;

    };

    class Application {
    public:
        Application();
        void new_Application(int file);
        void open_Application();
        void report_Documents();
        virtual Document* create_Document(int file) = 0;

    private:
        int index;
        std::vector<Document*> vd;
    };

    class MyApplication : public Application {
    public:
        MyApplication();
        Document* create_Document(int file) override ;
    };

}

#endif //DESIGN_PATTERN_FACTORY_METHOD_H
