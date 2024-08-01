#include "game.hpp"
#include "operator.hpp"
#include "surface.hpp"
#include <thread>
#include <iostream>
void task(void)
{
    Operator::instance()->get();
}

int main(int argc, char* argv[])
{
    std::thread th(task);
    th.detach();
    while(1)
    { 
        Game game;
        Surface::instance()->start(); //开始界面
        Operator::direction = Operator::BACK;
        while(Operator::RUN != Operator::direction);
        game.run();

    }
    return 0;
}