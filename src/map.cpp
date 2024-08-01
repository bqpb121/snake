#include "map.hpp"
#include <iostream>

Map::Map() : _rows(24), _cols(30), _cell_size(18), _gap_size(2)
{
    _cells = new Rect[_rows * _cols];
    for (int i = 0; i < _rows; i++)
    {
        for (int j = 0; j < _cols; j++)
        {
            _cells[i * _cols + j].resize(_cell_size, _cell_size);
            _cells[i * _cols + j].setpos(j * (_cell_size + _gap_size), i * (_cell_size + _gap_size));
        }
    }
}

Map::~Map() { delete[] _cells; }

void Map::draw(void)
{
    for (int i = 0; i < _rows; i++)
    {
        for (int j = 0; j < _cols; j++)
        {
            _cells[i * _cols + j].draw(0xDCDCDC);
            // std::cout<<"("<<i<<","<<j<<") ";
            if(i==0 || i== _rows-1 || j == 0 || j== _cols-1)
            {
                _cells[i * _cols + j].draw(0xA2AB3C);
            }
        }

    }
}
