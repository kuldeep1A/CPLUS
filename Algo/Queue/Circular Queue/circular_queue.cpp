#include <iostream>
using namespace std;

const int MAX_SIZE = 5; // Maximum size of the circluar queue

int queue[MAX_SIZE];
int front = -1, rear = -1; // Initialize front and rear indices

// Function to check if the queue is empty
bool isEmpty()
{
    return front == -1 && rear == -1;
}

// Function to check if the queue is full
bool isFull()
{
    return (rear + 1) % MAX_SIZE == front;
}

// Function to enqueue (insert) an item
void enqueue(int item)
{
    if (isFull())
    {
        cout << "Queue is full." << endl;
        return;
    }

    if (isEmpty())
    {
        front = rear = 0; // Set both front and rear to 0 for the first item
    }
    else
    {
        rear = (rear + 1) % MAX_SIZE;
    }

    queue[rear] = item; // Insert item at rear
    cout << item << " enqueued to queue" << endl;
}

// Function to dequeue (remove) an item
int dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return -1; // Return an error value
    }

    int item = queue[front]; // Retrieve item at front

    if (front == rear)
    {                      // If only one item in the queue
        front = rear = -1; // Reset to empty state
    }
    else
    {
        front = (front + 1) % MAX_SIZE; // Circular increment of front
    }

    return item;
}

// Function to peek (get the ffront item without removing)
int peek()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return -1; // Return an error value
    }

    return queue[front];
}

int main()
{
    // Ex. usage
    enqueue(10);
    enqueue(20);
    cout << "Dequeued: " << dequeue() << endl;
    enqueue(30);
    cout << "Front Item: " << peek() << endl;
    enqueue(40);
    enqueue(50);
    enqueue(100);
    enqueue(1000);
}
