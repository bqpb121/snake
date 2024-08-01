#ifndef _RECT_HPP_
#define _RECT_HPP_

#include "screen.hpp"
typedef struct Pos
{
    int x;
    int y;
} Pos;

class Rect
{
public:
    Rect() = default;
    Rect(int h, int w, Pos pos);
    void setpos(int x, int y);
    void resize(int h, int w);
    void draw(unsigned int color);
    ~Rect() {}

private:
    int _h;
    int _w;
    Pos _pos;
};

#endif