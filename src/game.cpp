#include "game.hpp"
#include "font.hpp"
#include <thread>

unsigned int Game::_max_score = 0;
unsigned int Game::_speed = 400;
Game::Game()
{
    _map = new Map;
    _snake = new Snake;
    // _bmp = new Bitmap("./key.bmp");
    _speed = 500;
}

Game::~Game()
{
    // delete _bmp;
    delete _map;
    // delete _snake;
}

void Game::setBackground(unsigned int color)
{
    for (int i = 0; i < 480; i++)
    {
        for (int j = 0; j < 800; j++)
        {
            Screen::instance()->draw(j, i, color);
        }
    }
}

void Game::run()
{
    //记录得分，如果与下一次得分不一样，则更新得分。
    int recode = Snake::_length;
    //设置背景颜色
    setBackground(0xFFFFFF);
    //绘制地图
    _map->draw();
    // _bmp->draw(600, 0);
    //绘制按键
    Surface::instance()->key();

    //显示得分
    char max_score[100]={0};
    sprintf(max_score, "历史最高分：%d", Game::_max_score);
    Font::instance()->show(620, 10, max_score);

    char cur_score[100] = {0};
    sprintf(cur_score, "当前已得分：%d", Snake::_length);
    Font::instance()->show(620, 50, cur_score);
    

    while (true)
    {
        int r = _snake->move();
        _snake->draw();
        
        std::cout<<r<<std::endl;

        if(r == 1 || r == 2 || r == 3)
        {
            if(Snake::_length > Game::_max_score )
            {
                Game::_max_score = Snake::_length; //记录最高分
                Snake::_length = 0;
            }
            Game::_speed = 400;
            // std::this_thread::sleep_for(std::chrono::milliseconds(500));
            Surface::instance()->gameover();
            
            std::cout<<"Operator::BACK:"<<Operator::BACK<<std::endl;
            Operator::direction = Operator::NONE;
            while(Operator::BACK != Operator::direction);
            std::cout<<"Operator::direction:"<<Operator::direction<<std::endl;
            // break;
            return;
        }
        //改变速度
        if(Game::_speed > 200 && recode != Snake::_length)
        {
            recode = Snake::_length;
            Game::_speed -= 2*Snake::_length;
        }
         std::this_thread::sleep_for(std::chrono::milliseconds(Game::_speed));
    }
}