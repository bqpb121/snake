#include "bitmap.hpp"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

Bitmap::Bitmap(const char *name) : _name(name)
{
    char buf[4];
    //打开图片文件
    int bmp_fd = open(name, O_RDWR);
    if (-1 == bmp_fd)
    {
        perror("open bmp failed");
        exit(1);
    }
    //读取位图宽
    lseek(bmp_fd, 0x12, SEEK_SET);
    read(bmp_fd, buf, 4); // 位图宽
    //解析
    _width = (buf[0]) | (buf[1] << 8) | (buf[2] << 16) | (buf[3] << 24);
    //读取位图高
    read(bmp_fd, buf, 4); // 位图高
    _height = (buf[0]) | (buf[1] << 8) | (buf[2] << 16) | (buf[3] << 24);
    //读取色深
    read(bmp_fd, buf, 4);
    _hpp = buf[2] | (buf[3] << 8); // 色深
    if (_hpp != 24 && _hpp != 32)
    {
        std::cout << "Not Suppost!" << std::endl;
        exit(1);
    }

    // int laizi = 0;
    //图片像素每行实际字节
    int line_bytes = abs(_width) * _hpp / 8;
    //图片每行字节
    int line_all_bytes;
    if (line_bytes % 4)
    {
        _laizi = 4 - line_bytes % 4;
    }

    line_all_bytes = line_bytes + _laizi;

    // 整个像素数组数据大小
    int read_bytes_size = line_all_bytes * abs(_height);
    // 用char类型装像素数组
    _pixels_array = new char[read_bytes_size * 4];

    lseek(bmp_fd, 0xA, SEEK_SET);
    read(bmp_fd, buf, 4);
    //解析图片像素起始位置
    int start = (buf[0]) | (buf[1] << 8) | (buf[2] << 16) | (buf[3] << 24);
    lseek(bmp_fd, start, SEEK_SET);
    //读取像素数组   
    read(bmp_fd, _pixels_array, read_bytes_size);
    close(bmp_fd);
}

void Bitmap::draw(int x0, int y0)
{
    char A = 0;
    char R = 0;
    char G = 0;
    char B = 0;
    int k = 0;

    unsigned int color;
    for (int j = 0; j < abs(_height); j++)
    {
        // if(j == 480)
        //     break;
        for (int i = 0; i < abs(_width); i++)
        {
            // if(i == 800)
            //     break;
            B = _pixels_array[k++];
            G = _pixels_array[k++];
            R = _pixels_array[k++];
            if (_hpp == 32)
            {
                A = _pixels_array[k++];
            }
            else
                A = 0;
            color = B | (G << 8) | (R << 16) | (A << 24);
            //调整位图方向
            int x = _width > 0 ? i : abs(_width) - 1 - i;
            int y = _height > 0 ? abs(_height) - 1 - j : j;

            Screen::instance()->draw(x0 + x, y0 + y, color); 
        }
        k+=_laizi;
    }
}

Bitmap::~Bitmap()
{
    delete[] _pixels_array;
}