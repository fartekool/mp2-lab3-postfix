#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <string>
#include "stack.h"


class TPostfix
{
    std::string infix;
    std::string postfix;
public:
    TPostfix()
    {
        infix = "(a+b*c)*(c/d-e)";
    }
    std::string GetInfix() { return infix; }
    std::string GetPostfix() { return postfix; }
    std::string ToPostfix();
    double Calculate(); // Ввод переменных, вычисление по постфиксной форме
};

#endif
