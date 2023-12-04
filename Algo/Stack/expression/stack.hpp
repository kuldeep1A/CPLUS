#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack() { top = NULL; }

    bool isEmpty() { return top == NULL; }

    void push(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }

        Node *temp = top;
        top = top->next;
        int poppedData = temp->data;
        delete temp;
        return poppedData;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return top->data;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }

        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << ", ";
            temp = temp->next;
        }
        cout << endl;
    }
};