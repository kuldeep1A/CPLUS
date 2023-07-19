// Write a program to check if given expression is balanced expression or not.

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalancedExpression(const std::string &expression)
{
    std::stack<char> stack;

    for (char c : expression)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            stack.push(c);
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            if (stack.empty())
            {
                return false;
            }

            char top = stack.top();
            stack.pop();

            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{'))
            {
                return false;
            }
        }
    }

    return stack.empty();
}

int main()
{
    std::string expression;

    std::cout << "Enter an expression: ";
    std::getline(std::cin, expression);

    if (isBalancedExpression(expression))
    {
        std::cout << "The expression is balanced." << std::endl;
    }
    else
    {
        std::cout << "The expression is not balanced." << std::endl;
    }

    return 0;
}
