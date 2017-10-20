//
// Created by Simon on 2017/10/19.
//

#include "prototype.h"

using namespace prototype;

std::vector<Image*> Image::prototypes;
int Image::nextSlot;
LandSatImage LandSatImage::landSatImage;
int LandSatImage::count = 1;

void Image::addPrototype(Image *image) {
    prototypes.push_back(image);
    nextSlot++;
}

Image* Image::findAndClone(imageType type) {
    for (int i = 0; i < nextSlot; ++i) {
        if (prototypes[i]->getType() == type) {
            return prototypes[i]->clone();
        }
    }
    return nullptr;
}

void LandSatImage::draw() {
    std::cout << "LandSatImage::draw " << id << std::endl;
}

imageType LandSatImage::getType() {
    return imageType::LSAT;
}

Image* LandSatImage::clone() {
    return new LandSatImage(1);
}

LandSatImage::LandSatImage(int dummy) {
    id = count++;
}

LandSatImage::LandSatImage() {
    addPrototype(this);
}

void SpotImage::draw() {
    std::cout << "SpotImage::draw " << id << std::endl;
}

imageType SpotImage::getType() {
    return imageType::SPOT;
}

Image* SpotImage::clone() {
    return new SpotImage(1);
}

SpotImage::SpotImage(int dummy) {
    id = count++;
}

SpotImage::SpotImage() {
    addPrototype(this);
}

SpotImage SpotImage::spotImage;
int SpotImage::count = 1;

