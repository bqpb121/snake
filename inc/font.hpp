#ifndef _FONT_HPP_
#define _FONT_HPP_
#include "screen.hpp"
#include "font.h"
class Font
{
public:
    static Font* instance()
    {
        static Font font;
        return &font;
    }
    ~Font();
    void show(int px, int py, char* str);
private:
    Font();
    font *_f;
	bitmap *_f_bit;
};
#endif