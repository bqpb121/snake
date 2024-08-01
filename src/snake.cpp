#include "snake.hpp"
int Sbody::_size = 18;
int Snake::_length = 0;

// Sbody默认构造函数，生成随机食物
Sbody::Sbody()
{
    _color = 0x00;
    srand(time(NULL));
    _x = (rand() % 27+1); 
    _y = (rand() % 21+1); 
    // draw();
}

Sbody::Sbody(int x, int y, unsigned int color) : _x(x), _y(y), _color(color){}
Sbody::~Sbody() {}

void Sbody::move(int x, int y)
{
    _x = x;
    _y = y;
}

// void Sbody::setColor(unsigned int color) { _color = color; }
int Sbody::getX() { return _x; }
int Sbody::getY() { return _y; }

int Sbody::getsize() { return Sbody::_size; }

unsigned int Sbody::SgetColor() { return _color; }

void Sbody::draw()
{
    for (int i = 0; i < _size; i++)
    {
        for (int j = 0; j < _size; j++)
        {
            Screen::instance()->draw(_x * 20 + j, _y * 20 + i, _color); // size(18)+gas_size(2)
        }
    }
}





// 初始化蛇
Snake::Snake() :_food(new Sbody)
{
    // srand(time(NULL));
    _body.push_back(new Sbody((rand()%27+1), (rand()%21+1), 0xFF0000));
    _dir = (Operator::Direction)(rand() % 4); // 随机生成移动方向。
}

// 析构函数，释放资源
Snake::~Snake()
{
    for (auto it = _body.begin(); it != _body.end(); )
    {
        delete *it; 
    }
    delete _food;
}

// 恢复尾巴后面的地图
void Snake::recover(int pos_x, int pos_y, unsigned int color)
{
    for (int i = 0; i < Sbody::_size; i++)
    {
        for (int j = 0; j < Sbody::_size; j++)
        {
                Screen::instance()->draw(pos_x*20 + i, pos_y*20 + j, color); //_cell_size(18)+gas_size(2) = 20;
        }
    }

}

// 头移动
void Snake::headmove(void)
{
    // 身体移动记录每个body下一个个body的坐标
    // bodymove();

    // 头移动。每次只改变一个坐标，且只走一步，加1
    switch (Operator::direction)
    {
    case Operator::LEFT:
        if (_dir == Operator::UP)
        {
            _body[0]->move(_body[0]->getX() - 1, _body[0]->getY());
            _dir = Operator::LEFT;
        }
        else if (_dir == Operator::DOWN)
        {
            _body[0]->move(_body[0]->getX() - 1, _body[0]->getY());
            _dir = Operator::LEFT;
        }
        else if(_dir == Operator::LEFT)
        {
            _body[0]->move(_body[0]->getX()-1, _body[0]->getY());
        }
        else if(_dir == Operator::RIGHT)
        {
            _body[0]->move(_body[0]->getX()+1, _body[0]->getY());
        }
        Operator::direction = Operator::NONE;
        break;
    case Operator::RIGHT:
        if (_dir == Operator::UP)
        {
            _body[0]->move(_body[0]->getX() + 1, _body[0]->getY());
            _dir = Operator::RIGHT;
        }
        else if (_dir == Operator::DOWN)
        {
            _body[0]->move(_body[0]->getX() + 1, _body[0]->getY());
            _dir = Operator::RIGHT;
        }
        else if(_dir == Operator::RIGHT)
        {
            _body[0]->move(_body[0]->getX()+1, _body[0]->getY());
        }
        else if(_dir == Operator::LEFT)
        {
            _body[0]->move(_body[0]->getX()-1, _body[0]->getY());
        }
        Operator::direction = Operator::NONE;
        break;
    case Operator::UP:
        if (_dir == Operator::LEFT)
        {
            _body[0]->move(_body[0]->getX(), _body[0]->getY() - 1);
            _dir = Operator::UP;
        }
        else if (_dir == Operator::RIGHT)
        {
            _body[0]->move(_body[0]->getX(), _body[0]->getY() - 1);
            _dir = Operator::UP;
        }
        else if(_dir == Operator::UP)
        {
            _body[0]->move(_body[0]->getX(), _body[0]->getY()-1);
        }
        else if(_dir == Operator::DOWN)
        {
            _body[0]->move(_body[0]->getX(), _body[0]->getY()+1);
        }
        Operator::direction = Operator::NONE;
        break;
    case Operator::DOWN:
        if (_dir == Operator::LEFT)
        {
            _body[0]->move(_body[0]->getX(), _body[0]->getY() + 1);
            _dir = Operator::DOWN;
        }
        else if (_dir == Operator::RIGHT)
        {
            _body[0]->move(_body[0]->getX(), _body[0]->getY() + 1);
            _dir = Operator::DOWN;
        }
        else if(_dir == Operator::DOWN)
        {
            _body[0]->move(_body[0]->getX(), _body[0]->getY()+1);
        }
        else if(_dir == Operator::UP)
        {
            _body[0]->move(_body[0]->getX(), _body[0]->getY()-1);
        }
        Operator::direction = Operator::NONE;
        break;
    case Operator::PAUSE:
        {
            Operator::direction = Operator::NONE;
           while(Operator::PAUSE != Operator::direction); 
           Operator::direction = Operator::NONE;
        }
        
    default:
        if (_dir == Operator::LEFT)
            _body[0]->move(_body[0]->getX() - 1, _body[0]->getY());
        else if (_dir == Operator::RIGHT)
            _body[0]->move(_body[0]->getX() + 1, _body[0]->getY());
        else if (_dir == Operator::UP)
            _body[0]->move(_body[0]->getX(), _body[0]->getY() - 1);
        else if (_dir == Operator::DOWN)
            _body[0]->move(_body[0]->getX(), _body[0]->getY() + 1);
    }
}

// 判断是否吃到食物
bool Snake::iseatfood(void)
{
    if (_body[0]->getX() == _food->getX() && _body[0]->getY() == _food->getY())
        return true;
    return false;
}

// 判断是否撞墙
bool Snake::iswall(void)
{
    if (_body[0]->getX() < 1 || _body[0]->getX() > 28 || _body[0]->getY() < 1 || _body[0]->getY() > 22)
        return true;
    return false;
}

// 判断是否撞自己
bool Snake::isself(void)
{
    for(int i=2; i<_body.size(); i++)
    {
        if(_body[0]->getX() == _body[i]->getX() && _body[0]->getY() == _body[i]->getY())
        {
            return true;
        }
    }
    return false;
}

// bool Snake::ispause()
// {
//     if(Operator::direction == Operator::PAUSE)
//     {
//         Operator::direction = Operator::NONE;
//         return true;
//     }
//     return false;
// }



// 蛇整体移动
int Snake::move(void)
{
    std::cout << "iswall:" << iswall() << std::endl;
    // 撞墙
    if (iswall())
    {
        // 游戏结束
        // do something;
        return 1;
    }
    std::cout << "isself:" << isself() << std::endl;
    // 撞自己
    if (isself())
    { // 游戏结束
        return 2;
    }



    std::cout << "iseatfood:" << iseatfood() << std::endl;
    // 吃到食物
    if (iseatfood())
    {
            _body.push_back(new Sbody(_body.back()->getX(), _body.back()->getY(), _food->SgetColor()));
        // 释放吃掉的食物
        delete _food;
        // 生成新的食物
        _food = new Sbody;
        // 蛇变长
        Snake::_length += 2;
        char cur_score[100] = {0};

        sprintf(cur_score, "当前已得分：%d", Snake::_length);
        Font::instance()->show(620, 50, cur_score);
    }

    int x = _body.back()->getX();
    int y = _body.back()->getY();
    std::cout<<"move_head1: "<<_body[0]->getX()<<","<<_body[0]->getY()<<std::endl;
    recover(x, y, 0xDCDCDC);
    //移动
    std::cout<<"move_body.size():"<<_body.size()<<std::endl;

    for(int i=_body.size()-1; i>0; i--)
    {
       _body[i]->move(_body[i-1]->getX(), _body[i-1]->getY());
       std::cout<<"_body:"<<i<<" ( "<<_body[i]->getX()<<","<<_body[i]->getY()<<")"<<std::endl;
    
    }
    std::cout<<"_body:0"<<" ( "<<_body[0]->getX()<<","<<_body[0]->getY()<<")"<<std::endl;
    std::cout<<"_food: "<<" ( )"<<_food->getX()<<","<<_food->getY()<<")"<<std::endl;
    headmove();


    std::cout<<"move_head2: "<<_body[0]->getX()<<","<<_body[0]->getY()<<std::endl;
    // draw();
    if (Snake::_length == 24*30) //24*30
    {
        // 游戏胜利
        return 3;
    }
    // if (isover())
    return 0;
}

void Snake::draw(void)
{
    std::cout<<"draw1"<<std::endl;
    for(auto i:_body)
    {
        i->draw();
    }
    std::cout<<"draw2"<<std::endl;
    _food->draw();
}