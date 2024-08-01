#ifndef _SURFACE_HPP_
#define _SURFACE_HPP_
#include "screen.hpp"
#include "bitmap.hpp"
class Surface
{
public:
    static Surface* instance()
    {
        static Surface surface;
        return &surface;
    }
    
    ~Surface();
    void start(void);
    void key(void);
    void back(void);
    void gameover(void);
    // void vin(void);
private:
    Surface();
    Surface(Surface& ) = delete;
    Surface& operator=(Surface& ) = delete;
    Bitmap* _start;
    // Bitmap* _key;
    Bitmap* _up;
    Bitmap* _down;
    Bitmap* _left;
    Bitmap* _right;
    Bitmap* _pause;
    Bitmap* _back;
    Bitmap* _gameover;
    // Bitmap* _vin;
};


#endif