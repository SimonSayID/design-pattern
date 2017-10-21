//
// Created by Simon on 2017/10/21.
//

#ifndef DESIGN_PATTERN_FLYWEIGHT_H
#define DESIGN_PATTERN_FLYWEIGHT_H

#include "../../main.h"

namespace flyweight {

    class Icon {
    public:
        explicit Icon(std::string fileName);
        const std::string getName();
        void draw(int x, int y);

    private:
        std::string name;
        int _width;
        int _height;
    };

    class FlyweightFactory {
    public:
        static Icon *getIcon(std::string name);
        static void reportTheIcons();

    private:
        enum {
            MAX_ICONS = 5
        };
        static int _numIcons;
        static Icon *_icons[MAX_ICONS];
    };

    class DialogBox {
    public:
        DialogBox(int x, int y, int incr);
        virtual void draw() = 0;

    protected:
        Icon *_icons[3];
        int _iconsOriginX;
        int _iconsOriginY;
        int _iconsIncrement;
    };

    class FileSelection : public DialogBox {
    public:
        FileSelection(Icon *first, Icon *second, Icon *third);
        void draw() override ;
    };

    class CommitTransaction : public DialogBox {
    public:
        CommitTransaction(Icon *first, Icon *second, Icon *third);
        void draw() override ;
    };
}

#endif //DESIGN_PATTERN_FLYWEIGHT_H
