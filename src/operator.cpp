#include "operator.hpp"

Operator::Direction Operator::direction = Operator::NONE;

Operator::Direction Operator::getDirection()
{
    int x = 0, y = 0;
    if (Touch::TouchClick == Touch::instance()->getDir())
    {
        x = Touch::instance()->getX();
        y = Touch::instance()->getY();

        if (620< x && x < 675 && y > 320 && y < 370)
        {
            return LEFT;
        }
        else if (725 < x && x < 780 && y > 320 && y < 370)
        {
            return RIGHT;
        }
        else if (660< x && x<730 && y>260 && y<320)
        {
            return UP;
        }
        else if (660<x && x<730 && y>370 && y<430)
        {
            return DOWN;
        }
        else if (675 < x && x<725 && y>320 && y<370)
        {
            return PAUSE;
        }
        else if(250< x && x<545 && y>320 && y<370)
        {
            return RUN;
        }
        else if(300<x && x<490 && y>300 && y<380)
        {
            return BACK;
        }
        return NONE;
    }
}

void Operator::get(void)
{
    while (1)
    {
        direction = getDirection();
    }
}
