#ifndef RGBACOLOR_H
#define RGBACOLOR_H


class RGBAColor {
private:
    unsigned R, G, B, A;
public:
    RGBAColor(unsigned R, unsigned G, unsigned B);
    RGBAColor(unsigned R, unsigned G, unsigned B, unsigned A);

    unsigned getR();
    unsigned getG();
    unsigned getB();
    unsigned getA();
};


#endif