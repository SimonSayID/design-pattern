//
// Created by Simon on 2017/10/19.
//

#ifndef DESIGN_PATTERN_PROTOTYPE_H
#define DESIGN_PATTERN_PROTOTYPE_H

#include "../../main.h"

namespace prototype {

    enum class imageType {
        LSAT, SPOT
    };

    class Image {
    public:
        virtual void draw() = 0;
        static Image* findAndClone(imageType type);

    protected:
        virtual imageType getType() = 0;
        virtual Image* clone() = 0;
        static void addPrototype(Image *image);

    private:
        static std::vector<Image *> prototypes;
        static int nextSlot;
    };

    class LandSatImage : public Image{
    public:
        void draw() override ;
        imageType getType() override;
        Image* clone() override ;

    protected:
        LandSatImage(int dummy);

    private:
        static LandSatImage landSatImage;
        LandSatImage();
        int id;
        static int count;
    };

    class SpotImage : public Image {
    public:
        void draw() override ;
        imageType getType() override;
        Image* clone() override ;

    protected:
        SpotImage(int dummy);

    private:
        SpotImage();
        static SpotImage spotImage;
        int id;
        static int count;
    };

}

#endif //DESIGN_PATTERN_PROTOTYPE_H
