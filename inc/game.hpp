#ifndef _GAME_HPP_
#define _GAME_HPP_
#include "snake.hpp"
#include "bitmap.hpp"
#include "map.hpp"
#include "surface.hpp"

class Game
{
public:
    Game();
    ~Game();
    void setBackground(unsigned int color);
    void run();
    static unsigned int _speed; //越大，速度越慢
private:
  
    static unsigned int _max_score;
    Map *_map; 
    // Bitmap *_bmp;
    Snake *_snake; 
    
};

#endif