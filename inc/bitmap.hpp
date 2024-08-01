#ifndef _BMP_HPP_
#define _BMP_HPP_
#include <iostream>
#include "screen.hpp"
class Bitmap
{
public:
    Bitmap(const char *name);
    void draw(int x0, int y0);
    ~Bitmap();

private:
    const char *_name;
    int _width;
    int _height;
    int _hpp;
    char *_pixels_array;
    int _laizi;
};
#endif