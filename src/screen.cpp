#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include "screen.hpp"

// 构造屏幕，并打开
Screen::Screen(const char *devpath, int w, int h) : _devname(devpath), _w(w), _h(h)
{
    _fd = open(_devname, O_RDWR);
    if (-1 == _fd)
    {
        perror("open faild");
        exit(1);
    }
    _plcd = (int *)mmap(NULL, _w * _h * 4, PROT_READ | PROT_WRITE, MAP_SHARED, _fd, 0);
    if (MAP_FAILED == _plcd)
    {
        perror("mmap faild");
        exit(1);
    }
}

// 析构，释放资源
Screen::~Screen()
{
    munmap(_plcd, _w * _h * 4);
    close(_fd);
}

int Screen::getW(void)
{
    return _w;
}
int Screen::getH(void)
{
    return _h;
}
int Screen::getfd(void)
{
    return _fd;
}
int *Screen::getplcd(void)
{
    return _plcd;
}

// 屏幕像素点绘制
void Screen::draw(int x, int y, unsigned int color)
{
    if (x < 0 || x > 800 || y < 0 || y > 480)
        return;
    *(_plcd + _w * y + x) = color;
}