#include "font.hpp"
#include <stdio.h>


Font::Font()
{
    //初始化字库
	_f = fontLoad("/usr/share/fonts/DroidSansFallback.ttf");
}

Font::~Font()
{
    fontUnload(_f);
    destroyBitmap(_f_bit);
}


void Font::show(int px, int py, char* str)
{
    //设置字体的大小
    fontSetSize(_f, 30);

	//设置字体输出框的大小
	_f_bit = createBitmapWithInit(200, 100, 4, getColor(0, 255, 255, 255));
    fontPrint(_f, _f_bit, 0, 0, str, getColor(0,255,0,0), 0);
    show_font_to_lcd(reinterpret_cast<unsigned int*>(Screen::instance()->getplcd()), px, py, _f_bit);
}