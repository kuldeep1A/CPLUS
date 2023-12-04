#include <iostream>
#include "stack.hpp"

int postfix_eval(string postfix_expr)
{
    Stack stack;

    for (char c : postfix_expr)
    {
        if (isdigit(c))
        {
            stack.push(c - '0');
        }
        else
        {
            int operand2 = stack.pop();
            int operand1 = stack.pop();
            int result = 0;

            switch (c)
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            }
            stack.push(result);
        }
    }
    return stack.pop();
};

int main()
{
    string postfix_expr = "53+2*";
    int result = postfix_eval(postfix_expr);
    cout << "Answer is: " << result << endl;

    return 0;
};