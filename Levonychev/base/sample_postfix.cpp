#include <iostream>
#include <string>
#include "tpostfix.h"
#include "stack.h"
#include <map>

int main()
{   
    std::cout << "This is a line calculator. You can use the following operations: +, -, *, /" << std::endl;
    std::cout << "Enter \"0\" if you want to close the program" << std::endl;
    while(1)
    {
        std::cout << "\n\nEnter the arithmetic expression: " << std::endl;
        std::string arithmetic_expression;
        getline(std::cin, arithmetic_expression);
        if (arithmetic_expression == "0")
        {
            std::cout << "Good bye :)" << std::endl;
            return 0;
        }
        TPostfix expression(arithmetic_expression);

        std::cout << "You entered this expression: " << expression.GetInfix() << std::endl;
        std::cout << "Postfix form of the entered expression: ";
        for (const auto& lexem : expression.GetPostfix())
            std::cout << lexem;
        std::cout << std::endl;

        std::vector<std::string> operands = expression.GetOperands();
        std::map<std::string, double> values;
        double value;
        for (const auto& operand : operands)
        {
            std::cout << "Enter value for " << operand << ": ";
            std::cin >> value;
            values[operand] = value;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cout << "The result of calculating the entered arithmetic expression: " << expression.Calculate(values) << std::endl;
    }
}