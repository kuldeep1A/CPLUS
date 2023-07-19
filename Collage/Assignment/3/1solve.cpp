// write a program to implement stack using array.
#include <iostream>
#define MAX_SIZE 100

using namespace std;

class Stack
{
private:
    int stack[MAX_SIZE];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == MAX_SIZE - 1;
    }

    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack pura bara huaa hai." << endl;
        }

        stack[++top] = value;
        cout << "Pushed " << value << " onto the stack." << endl;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is khali hai." << endl;
            return -1;
        }

        return stack[top--];
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is khali hai." << endl;
            return -1;
        }

        return stack[top];
    }

    int size()
    {
        return top + 1;
    }
};

int main()
{
    Stack stack;
    stack.push(3);
    stack.push(2);
    stack.push(1);

    cout << "Size of the stack: " << stack.size() << endl;
    cout << "Top element: " << stack.peek() << endl;
    cout << "Popped element: " << stack.pop() << endl;
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "NO") << endl;

    return 0;
}
