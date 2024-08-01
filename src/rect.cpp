#include <iostream>
#include "rect.hpp"

Rect::Rect(int h, int w, Pos pos)
{
    _h = h;
    _w = w;
    // _pos.x = pos.x;
    // _pos.y = pos.y;
    _pos = pos;
}

void Rect::resize(int h, int w)
{
    _h = h;
    _w = w;
}

void Rect::setpos(int x, int y)
{
    _pos.x = x;
    _pos.y = y;
}

void Rect::draw(unsigned int color)
{
    for (int i = 0; i < _h; i++)
    {
        for (int j = 0; j < _w; j++)
        {
            Screen::instance()->draw(j + _pos.x, i + _pos.y, color);
        }
    }
}
