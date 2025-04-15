#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;

public:
    Node() : data(0), next(NULL) {}
    Node(int d) : data(d), next(NULL) {}

    int getdata() { return data; }
    void setdata(int d) { data = d; }
    Node *getnext() { return next; }
    void setnext(Node *n) { next = n; }
};

class CircularLinkedList
{
    Node *head;

public:
    CircularLinkedList() : head(NULL) {}

    void append(Node *n)
    {
        if (head == NULL)
        {
            head = n;
            n->setnext(n);
        }
        else
        {
            Node *ptr = head;
            while (ptr->getnext() != head)
            {
                ptr = ptr->getnext();
            }
            ptr->setnext(n);
            n->setnext(head);
        }
    }

    void prepend(Node *n)
    {
        if (head == NULL)
        {
            head = n;
            n->setnext(n);
        }
        else
        {
            Node *ptr = head;
            while (ptr->getnext() != head)
            {
                ptr = ptr->getnext();
            }
            ptr->setnext(n);
            n->setnext(head);
            head = n;
        }
    }

    int count()
    {
        if (head == NULL)
            return 0;
        int c = 1;
        Node *ptr = head->getnext();
        while (ptr != head)
        {
            c++;
            ptr = ptr->getnext();
        }
        return c;
    }

    void insert(int pos, Node *n)
    {
        int c = count();
        if (pos < 1 || pos > c + 1)
        {
            cout << "invalid position" << endl;
            return;
        }
        if (pos == 1)
        {
            prepend(n);
        }
        else
        {
            Node *ptr = head;
            for (int i = 1; i < pos - 1; i++)
            {
                ptr = ptr->getnext();
            }
            n->setnext(ptr->getnext());
            ptr->setnext(n);
        }
    }

    void deletenode(int pos)
    {
        int c = count();
        if (pos < 1 || pos > c)
        {
            cout << "invalid position" << endl;
            return;
        }

        if (pos == 1)
        {
            if (head->getnext() == head)
            {
                head = NULL;
            }
            else
            {
                Node *ptr = head;
                while (ptr->getnext() != head)
                {
                    ptr = ptr->getnext();
                }
                ptr->setnext(head->getnext());
                head = head->getnext();
            }
        }
        else
        {
            Node *prev = head;
            for (int i = 1; i < pos - 1; i++)
            {
                prev = prev->getnext();
            }
            Node *curr = prev->getnext();
            prev->setnext(curr->getnext());
        }
    }

    void update(int pos, int val)
    {
        int c = count();
        if (pos < 1 || pos > c)
        {
            cout << "invalid position" << endl;
            return;
        }
        Node *ptr = head;
        for (int i = 1; i < pos; i++)
        {
            ptr = ptr->getnext();
        }
        ptr->setdata(val);
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "list is empty" << endl;
            return;
        }
        Node *ptr = head;
        do
        {
            cout << ptr->getdata() << " ";
            ptr = ptr->getnext();
        } while (ptr != head);
        cout << endl;
    }
};

int main()
{
    Node *n1 = new Node(10);
    Node *n2 = new Node(20);
    Node *n3 = new Node(30);
    Node *n4 = new Node(40);
    Node *n5 = new Node(99);

    CircularLinkedList cll;
    cll.append(n1);
    cll.append(n2);
    cll.append(n3);
    cll.append(n4);
    cll.display();

    cout << cll.count() << endl;

    cll.insert(3, n5);
    cll.display();

    cll.deletenode(1);
    cll.display();

    cll.update(1, 79);
    cll.display();

    return 0;
}
