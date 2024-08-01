#ifndef _OPERATOR_HPP_
#define _OPERATOR_HPP_

#include "touch.hpp"

class Operator
{
public:
    typedef enum
    {
        LEFT,
        RIGHT,
        UP,
        DOWN,
        PAUSE,
        RUN,
        BACK,
        NONE
    } Direction;  //操作枚举类型

    //Operator 单例
    static Operator *instance()
    {
        static Operator instance;
        return &instance;
    }
    //获取操作枚举
    Direction getDirection();
    
    static Direction direction;
    void get(void);

private:
    Operator() {}
    Operator(const Operator &) = delete;
    Operator &operator=(const Operator &) = delete;
};

#endif /* _OPERATOR_HPP_ */