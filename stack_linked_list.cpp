#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(NULL) {}
};

class Stack
{
    Node *top;

public:
    Stack() : top(NULL) {}

    bool isEmpty()
    {
        return top == NULL;
    }

    void push(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return 0;
        }
        int val = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        return val;
    }

    int count()
    {
        int cnt = 0;
        Node *temp = top;
        while (temp)
        {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    int peek(int pos)
    {
        if (pos < 1 || pos > count())
        {
            cout << "Invalid position" << endl;
            return 0;
        }
        Node *temp = top;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }

    void change(int pos, int val)
    {
        if (pos < 1 || pos > count())
        {
            cout << "Invalid position" << endl;
            return;
        }
        Node *temp = top;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        temp->data = val;
        cout << "Value changed at position " << pos << endl;
    }

    void display()
    {
        Node *temp = top;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack s;
    int option, position, value;

    do
    {
        cout << "1. Push()\n2. Pop()\n3. isEmpty()\n4. Peek()\n5. Count()\n6. Change()\n7. Display()\n8. Clear Screen\n0. Exit\n";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            cout << "Popped value: " << s.pop() << endl;
            break;
        case 3:
            cout << (s.isEmpty() ? "Stack is Empty" : "Stack is Not Empty") << endl;
            break;
        case 4:
            cout << "Enter position to peek: ";
            cin >> position;
            cout << "Value at position " << position << " is " << s.peek(position) << endl;
            break;
        case 5:
            cout << "Number of items in stack: " << s.count() << endl;
            break;
        case 6:
            cout << "Enter position to change: ";
            cin >> position;
            cout << "Enter new value: ";
            cin >> value;
            s.change(position, value);
            break;
        case 7:
            s.display();
            break;
        case 8:
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
