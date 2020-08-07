#include "model/RGBAColor.h"
#include <iostream>

RGBAColor::RGBAColor(unsigned R, unsigned G, unsigned B) {
    this->R = R;
    this->G = G;
    this->B = B;
    this->A = 0xFF;
}
RGBAColor::RGBAColor(unsigned R, unsigned G, unsigned B, unsigned A) {
    this->R = R;
    this->G = G;
    this->B = B;
    this->A = A;
}

unsigned RGBAColor::getR() {
    return R;
}

unsigned RGBAColor::getG() {
    return G;
}

unsigned RGBAColor::getB() {
    return B;
}

unsigned RGBAColor::getA() {
    return A;
}
