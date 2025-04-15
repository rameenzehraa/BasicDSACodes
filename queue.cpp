#include <iostream>

using namespace std;

class Queue
{
    int arr[5];
    int front;
    int rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (rear + 1) % 5 == front;
    }

    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        if (isEmpty())
        {
            front = 0;
        }
        rear = (rear + 1) % 5;
        arr[rear] = val;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1; // Return an invalid value
        }
        int value = arr[front];
        if (front == rear)
        {
            front = rear = -1; // Queue is empty
        }
        else
        {
            front = (front + 1) % 5;
        }
        return value;
    }

    int count()
    {
        if (isEmpty())
            return 0;
        if (rear >= front)
        {
            return rear - front + 1;
        }
        return 5 - front + rear + 1; // Circular queue case
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        int i = front;
        while (i != rear)
        {
            cout << arr[i] << " ";
            i = (i + 1) % 5;
        }
        cout << arr[rear] << endl; // Print rear element
    }
};

int main()
{
    Queue q1;
    int value, option;

    do
    {
        cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. count()" << endl;
        cout << "6. display()" << endl;
        cout << "7. Clear Screen" << endl;

        cin >> option;

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Enter an item to Enqueue in the Queue: ";
            cin >> value;
            q1.enqueue(value);
            break;
        case 2:
            cout << "Dequeued Value: " << q1.dequeue() << endl;
            break;
        case 3:
            cout << (q1.isEmpty() ? "Queue is Empty" : "Queue is not Empty") << endl;
            break;
        case 4:
            cout << (q1.isFull() ? "Queue is Full" : "Queue is not Full") << endl;
            break;
        case 5:
            cout << "Number of items in the Queue: " << q1.count() << endl;
            break;
        case 6:
            cout << "Queue contents: ";
            q1.display();
            break;
        case 7:
            system("cls");
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    } while (option != 0);

    return 0;
}
