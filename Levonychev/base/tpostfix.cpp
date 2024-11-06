#include "tpostfix.h"
#include "stack.h"


map<char, int> TPostfix::priority = { { '(', 0 }, { '+', 1 }, { '-', 1 }, { '*', 2 }, { '/', 2 } };

void TPostfix::Parse()
{
    string lexem = "";
    int count1 = 0, count2 = 0;
    for (int i = 0; i < infix.length(); ++i)
    {
        if (infix[i] == '(')
            ++count1;
        if (infix[i] == ')')
            ++count2;
    }
    if (count1 != count2)
        throw "Different numbers of opening and closing brackets";
    for (auto c : infix)
    {
        if (c == ' ')
            continue;
        if (c == ')' || priority.count(c) > 0)
        {
            if (!lexem.empty())
                lexems.push_back(lexem);
            lexems.push_back(string{ c });
            lexem = "";
            continue;
        }
        lexem += c;
    }
    if (!lexem.empty())
        lexems.push_back(lexem);
}

void TPostfix::ToPostfix()
{
    Parse();
    TStack<string> stack(100);
    string stackElement;
    int i = 0;
    for (auto element : lexems)
    {
        if (element[0] == '(')
            stack.Push(element);
        else if (element[0] == ')')
        {
            stackElement = stack.Top();
            stack.Pop();
            while (stackElement[0] != '(')
            {
                postfix.push_back(stackElement);
                stackElement = stack.Top();
                stack.Pop();
            }
        }
        else if (element[0] == '+' || element[0] == '-' || element[0] == '*' || element[0] == '/')
        {
            while (!stack.Empty())
            {
                stackElement = stack.Top();
                stack.Pop();
                if (priority[element[0]] <= priority[stackElement[0]])
                    postfix.push_back(stackElement);
                else
                {
                    stack.Push(stackElement);
                    break;
                }
            }
            stack.Push(element);
        }
        else
        {
            double value = 0.0;
            try
            {
                value = stod(element);
                const_operands.insert(element);
            }
            catch (invalid_argument) {}

            operands.insert({ element, value });
            postfix.push_back(element);
        }
    }
    while (!stack.Empty())
    {
        stackElement = stack.Top();
        stack.Pop();
        postfix.push_back(stackElement);
    }
    if (postfix.empty())
        throw "Wrong expression";
}

vector<string> TPostfix::GetOperands()
{
    vector<string> result;
    for (const auto& element : operands)
    {
        if (element.first.empty())
            continue;
        if (const_operands.count(element.first))
            continue;
        result.push_back(element.first);
    }
    return result;
}

double TPostfix::Calculate(const map<string, double>& values)
{   
    for (auto& value : values)
    {
        const auto& opValue = operands.find(value.first);
        if (opValue == operands.end())
            continue;
        opValue->second = value.second;
    }
    TStack<double> stack(100);
    double lhs, rhs;
    for (auto lexem : postfix)
    {
        if (lexem[0] == '+')
        {
            rhs = stack.Top();
            stack.Pop();
            lhs = stack.Top();
            stack.Pop();
            stack.Push(lhs + rhs);
        }
        else if (lexem[0] == '-')
        {
            rhs = stack.Top();
            stack.Pop();
            lhs = stack.Top();
            stack.Pop();
            stack.Push(lhs - rhs);
        }
        else if (lexem[0] == '*')
        {
            rhs = stack.Top();
            stack.Pop();
            lhs = stack.Top();
            stack.Pop();
            stack.Push(lhs * rhs);
        }
        else if (lexem[0] == '/')
        {
            rhs = stack.Top();
            stack.Pop();
            lhs = stack.Top();
            stack.Pop();
            stack.Push(lhs / rhs);
        }
        else
            stack.Push(operands[lexem]);
    }
    return stack.Top();
}