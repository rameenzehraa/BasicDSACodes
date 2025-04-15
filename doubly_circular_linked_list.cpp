#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;
    Node *prev;

public:
    Node() : data(0), next(NULL), prev(NULL) {}
    Node(int d) : data(d), next(NULL), prev(NULL) {}

    int getdata() { return data; }
    void setdata(int d) { data = d; }
    Node *getnext() { return next; }
    void setnext(Node *n) { next = n; }
    Node *getprev() { return prev; }
    void setprev(Node *p) { prev = p; }
};

class DoublyCircularLinkedList
{
    Node *head;

public:
    DoublyCircularLinkedList() : head(NULL) {}

    void append(Node *n)
    {
        if (head == NULL)
        {
            head = n;
            n->setnext(n);
            n->setprev(n);
        }
        else
        {
            Node *tail = head->getprev();
            tail->setnext(n);
            n->setprev(tail);
            n->setnext(head);
            head->setprev(n);
        }
    }

    void prepend(Node *n)
    {
        if (head == NULL)
        {
            head = n;
            n->setnext(n);
            n->setprev(n);
        }
        else
        {
            Node *tail = head->getprev();
            n->setnext(head);
            n->setprev(tail);
            head->setprev(n);
            tail->setnext(n);
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
            return;

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
            Node *nxt = ptr->getnext();
            n->setnext(nxt);
            n->setprev(ptr);
            ptr->setnext(n);
            nxt->setprev(n);
        }
    }

    void deletenode(int pos)
    {
        int c = count();
        if (pos < 1 || pos > c)
            return;

        if (c == 1)
        {
            head = NULL;
        }
        else if (pos == 1)
        {
            Node *tail = head->getprev();
            Node *nxt = head->getnext();
            tail->setnext(nxt);
            nxt->setprev(tail);
            head = nxt;
        }
        else
        {
            Node *ptr = head;
            for (int i = 1; i < pos; i++)
            {
                ptr = ptr->getnext();
            }
            Node *prv = ptr->getprev();
            Node *nxt = ptr->getnext();
            prv->setnext(nxt);
            nxt->setprev(prv);
        }
    }

    void update(int pos, int val)
    {
        int c = count();
        if (pos < 1 || pos > c)
            return;

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

    DoublyCircularLinkedList dcll;
    dcll.append(n1);
    dcll.append(n2);
    dcll.append(n3);
    dcll.append(n4);
    dcll.display();

    cout << dcll.count() << endl;

    dcll.insert(3, n5);
    dcll.display();

    dcll.deletenode(1);
    dcll.display();

    dcll.update(1, 79);
    dcll.display();

    return 0;
}
