#include "touch.hpp"
Touch::Touch(const char *name) : _devname(name)
{
    _fd = open(_devname, O_RDWR);
    if (-1 == _fd)
        throw std::runtime_error("open touch_dev error");
}
Touch::~Touch()
{
    close(_fd);
}

Touch::TouchDirection Touch::getDir(void)
{
    // 读取触摸屏文件的输入数据并进行解析
    struct input_event ev;
    int start_x, start_y;
    int end_x, end_y;
    int flag_x = 0, flag_y = 0;

    while (1)
    {
        int res = read(_fd, &ev, sizeof(ev)); // 只要没有点击屏幕，阻塞在read这代码
        if (res != sizeof(ev))                // 读取数据不完整
        {
            continue; // 继续下一次读取
        }

        // 解析读取出来的数据，解析结构体成员type code value
        if (ev.type == EV_ABS && ev.code == ABS_X) // 代表的绝对x坐标轴
        {
            if (flag_x == 0)
            {
                start_x = ev.value * 800 * 1.0 / 1040;
                end_x = ev.value * 800 * 1.0 / 1040;
                flag_x = 1; // 表示获取到了起始x坐标
                printf("第一次 :ev_x = %d\n", start_x);
            }
            else
            {
                end_x = ev.value * 800 * 1.0 / 1040;
                printf("第二次 :ev_x = %d\n", end_x);
            }
        }
        else if (ev.type == EV_ABS && ev.code == ABS_Y) // 代表的绝对y坐标轴
        {
            if (flag_y == 0)
            {
                start_y = ev.value * 480 * 1.0 / 600; // 等比缩放
                end_y = ev.value * 480 * 1.0 / 600;
                flag_y = 1; // 表示获取到了起始y坐标
                printf("第一次 :ev_y = %d\n", start_y);
            }
            else
            {
                end_y = ev.value * 480 * 1.0 / 600;
                printf("第二次 :ev_y = %d\n", end_y);
            }
        }
        if (ev.type == EV_KEY && ev.code == BTN_TOUCH && ev.value == 0) // 手指离开屏幕
        {
            // 得到（start_x, start_y）和（end_x, end_y)
            // 根据拿到的两个坐标判断滑动方向
            _x = end_x;
            _y = end_y;
            printf("************(%d, %d) *****************\n", _x, _y);
            if (start_x == end_x && start_y == end_y)
                return TouchClick; // 点击
            else
            {
                if (start_x > end_x)
                    return TouchLeft;
                else
                    return TouchRight;
            }
            break;
        }
    }
}

int Touch::getX(void)
{
    return _x;
}
int Touch::getY(void)
{
    return _y;
}