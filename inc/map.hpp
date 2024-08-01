#ifndef _MAP_HPP_
#define _MAP_HPP_
#include "screen.hpp"
#include "rect.hpp"
class Map
{
public:
    Map();
    ~Map();
    // void display();
    void draw(void);
    // void print(void);
private:
    int _rows;      // 行，高
    int _cols;      // 列，宽
    int _cell_size; // 矩形大小
    int _gap_size;  // 间隙
    Rect *_cells;   // 矩形数目
};

#endif /* _MAP_HPP_ */