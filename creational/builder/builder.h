//
// Created by Simon on 2017/10/17.
//

#ifndef DESIGN_PATTERN_BUILDER_H
#define DESIGN_PATTERN_BUILDER_H

#include "../../main.h"

namespace builder {

    enum class PersistenceType {
        File, Queue, Pathway
    };

    struct PersistenceAttribute {
        PersistenceType type;
        std::string value;
    };

    class DistributedWorkPackage {
    public:
        explicit DistributedWorkPackage(std::string type);
        void setFile(std::string f, std::string v);
        void setQueue(std::string f, std::string v);
        void setPathway(std::string f, std::string v);
        const std::string getState();

    private:
        std::string desc, temp;
    };

    class Builder {
    public:
        virtual void configureFile(std::string) = 0;
        virtual void configureQueue(std::string) = 0;
        virtual void configurePathway(std::string) = 0;
        DistributedWorkPackage* getResult();

    protected:
        DistributedWorkPackage *result = nullptr;
    };

    class UnixBuilder : public Builder {
    public:
        UnixBuilder();
        void configureFile(std::string file) override ;
        void configureQueue(std::string queue) override ;
        void configurePathway(std::string type) override ;
    };

    class VmsBuilder : public Builder {
    public:
        VmsBuilder();
        void configureFile(std::string file) override ;
        void configureQueue(std::string queue) override ;
        void configurePathway(std::string type) override ;
    };

    class Reader {
    public:
        void setBuilder(Builder *b);
        void construct(std::vector<PersistenceAttribute> vp);

    private:
        Builder *bb;
    };

}

#endif //DESIGN_PATTERN_BUILDER_H
