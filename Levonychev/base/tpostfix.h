#ifndef POSTFIX_H
#define POSTFIX_H

#include "stack.h"
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

class TPostfix
{
    string infix;
    vector<string> postfix;
    vector<string> lexems;
    static map<char, int> priority;
    map<string, double> operands;
    set<string> const_operands;

    void Parse();
    void ToPostfix();
public:
    TPostfix(string infix_ = "a+b") : infix(infix_)
    {
        if (infix.empty())
            throw invalid_argument("String is empty");
        ToPostfix();
    }
    string GetInfix() const { return infix; }
    vector<string> GetPostfix() const { return postfix; }
    vector<string> GetOperands();
    double Calculate(const map<string, double>& values = {});
};

#endif