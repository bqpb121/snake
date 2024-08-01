#ifndef _TOUCH_HPP_
#define _TOUCH_HPP_

#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <iostream>
#include <stdexcept>
class Touch
{
private:
    Touch(const char *name);
    Touch(const Touch &) = delete;
    Touch &operator=(const Touch &) = delete;

    const char *_devname;
    int _fd;
    int _x;
    int _y;

public:
    typedef enum
    {
        TouchError, // 错误码
        TouchClick, // 点击的
        TouchLeft,  // 左滑
        TouchRight  // 右滑
    } TouchDirection;

    static Touch *instance()
    {
        static Touch instance("/dev/input/event0");
        return &instance;
    }
    ~Touch();
    TouchDirection getDir(void);
    int getX(void);
    int getY(void);
};

#endif