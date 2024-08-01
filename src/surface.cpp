#include "surface.hpp"
Surface::Surface()
{
    _start = new Bitmap("./start.bmp");
    _up    = new Bitmap("./up.bmp");
    _down  = new Bitmap("./down.bmp");
    _left  = new Bitmap("./left.bmp");
    _right = new Bitmap("./right.bmp");
    _pause = new Bitmap("./pause.bmp");
    // _key   = new Bitmap("./key.bmp");
    _back  = new Bitmap("./back.bmp");
    _gameover = new Bitmap("./gameover.bmp");
    // _vin = new Bitmap("./win.bmp");
}

Surface::~Surface() 
{ 
    delete _start; 
    delete _back; 
    delete _up;
    delete _down;
    delete _left;
    delete _right;
    delete _pause;
    delete _gameover; 
}

void Surface::start(void)
{
    _start->draw(0, 0);
}

void Surface::key(void)
{
    _up->draw(675, 270);  //50*50像素
    _down->draw(675, 370);
    _left->draw(625,320);
    _right->draw(725,320);
    _pause->draw(675,320);
   // Bitmap("./pause.bmp").draw(625,405);
}

void Surface::back(void) 
{
     _back->draw(725, 405); // 
}

void Surface::gameover(void) 
{
    _gameover->draw(0, 0); //
}

// void Surface::vin(void)
// {
//     _vin->draw(0, 0); //
// }
