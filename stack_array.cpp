#include <iostream>
using namespace std;

class Stack
{
    int top;
    int arr[5];

public:
    Stack()
    {
        top = -1;
        for (int i = 0; i < 5; i++)
            arr[i] = 0;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == 4;
    }

    void push(int val)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            arr[++top] = val;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return 0;
        }
        else
        {
            int popValue = arr[top];
            arr[top--] = 0;
            return popValue;
        }
    }

    int count()
    {
        return top + 1;
    }

    int peek(int pos)
    {
        if (pos < 1 || pos > count())
        {
            cout << "Invalid position" << endl;
            return 0;
        }
        return arr[pos - 1];
    }

    void change(int pos, int val)
    {
        if (pos < 1 || pos > count())
        {
            cout << "Invalid position" << endl;
            return;
        }
        arr[pos - 1] = val;
        cout << "Value changed at position " << pos << endl;
    }

    void display()
    {
        for (int i = 4; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack s1;
    int option, position, value;

    do
    {
        cout << "1. Push()\n2. Pop()\n3. isEmpty()\n4. isFull()\n5. Peek()\n6. Count()\n7. Change()\n8. Display()\n9. Clear Screen\n0. Exit\n";
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s1.push(value);
            break;
        case 2:
            cout << "Popped value: " << s1.pop() << endl;
            break;
        case 3:
            cout << (s1.isEmpty() ? "Stack is Empty" : "Stack is Not Empty") << endl;
            break;
        case 4:
            cout << (s1.isFull() ? "Stack is Full" : "Stack is Not Full") << endl;
            break;
        case 5:
            cout << "Enter position to peek: ";
            cin >> position;
            cout << "Value at position " << position << " is " << s1.peek(position) << endl;
            break;
        case 6:
            cout << "Number of items in stack: " << s1.count() << endl;
            break;
        case 7:
            cout << "Enter position to change: ";
            cin >> position;
            cout << "Enter new value: ";
            cin >> value;
            s1.change(position, value);
            break;
        case 8:
            s1.display();
            break;
        case 9:
            system("cls");
            break;
        case 0:
            break;
        default:
            cout << "Invalid option" << endl;
        }
    } while (option != 0);

    return 0;
}
