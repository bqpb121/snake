#ifndef _SNAKE_HPP_
#define _SNAKE_HPP_

#include <vector>
#include "bitmap.hpp"
#include <stdlib.h>
#include "operator.hpp"
#include "font.hpp"
class Sbody
{
public:
    Sbody();
    Sbody(int x, int y, unsigned int color);
    ~Sbody();
    int getX();
    int getY();
    int getsize();
    void move(int x, int y);
    unsigned int SgetColor();
    virtual void draw();
    static int _size; // 大小
    
private:
    int _x; // rowsXcols数组位置 30X40
    int _y; 
    unsigned int _color;
};


class Snake
{
private:
    std::vector<Sbody *> _body; // 身体
    Operator::Direction _dir;   // 随机
    Sbody *_food;   //食物

public:
    Snake();
    Snake(int x, int y);
    ~Snake();
    static int _length; // 长度,初始为1，即蛇头
    // void move(int x, int y);
    //int getLength();
    void headmove();
    int move();
    void draw();
    // void bodymove();
    bool iseatfood();
    bool iswall();
    bool isself();
    bool ispause();
    // void change();
    void recover(int pos_x, int pos_y, unsigned int color);
};

#endif