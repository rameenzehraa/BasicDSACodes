#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;
    Node *previous;

public:
    Node() : data(0), next(NULL), previous(NULL) {}
    Node(int d) : data(d), next(NULL), previous(NULL) {}

    int getdata() { return data; }
    void setdata(int abc) { data = abc; }
    void setnext(Node *abc) { next = abc; }
    Node *getnext() { return next; }
    void setprevious(Node *abc) { previous = abc; }
    Node *getprevious() { return previous; }
};

class DoublyLinkedList
{
    Node *head;

public:
    DoublyLinkedList() : head(NULL) {}

    void append(Node *n)
    {
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            Node *ptr = head;
            while (ptr->getnext() != NULL)
            {
                ptr = ptr->getnext();
            }
            ptr->setnext(n);
            n->setprevious(ptr);
        }
    }

    void prepend(Node *n)
    {
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            n->setnext(head);
            head->setprevious(n);
            head = n;
        }
    }

    int count()
    {
        int j = 0;
        Node *ptr = head;
        while (ptr != NULL)
        {
            j++;
            ptr = ptr->getnext();
        }
        return j;
    }

    void insert(int pos, Node *n)
    {
        if (pos > count() || pos < 1)
        {
            cout << "wrong position entered" << endl;
        }
        else
        {
            if (pos == 1)
            {
                n->setnext(head);
                if (head != NULL)
                    head->setprevious(n);
                head = n;
            }
            else
            {
                Node *curr = head;
                for (int i = 1; i < pos - 1; i++)
                {
                    curr = curr->getnext();
                }
                Node *next = curr->getnext();
                n->setnext(next);
                if (next != NULL)
                    next->setprevious(n);
                curr->setnext(n);
                n->setprevious(curr);
            }
        }
    }

    void deletenode(int pos)
    {
        if (pos > count() || pos < 1)
        {
            cout << "wrong position number" << endl;
        }
        else
        {
            if (pos == 1 && head->getnext() == NULL)
            {
                head = NULL;
            }
            else if (pos == 1)
            {
                head = head->getnext();
                head->setprevious(NULL);
            }
            else if (pos == count())
            {
                Node *ptr = head;
                for (int i = 1; i < pos - 1; i++)
                {
                    ptr = ptr->getnext();
                }
                ptr->setnext(NULL);
            }
            else
            {
                Node *curr = head;
                for (int i = 1; i < pos - 1; i++)
                {
                    curr = curr->getnext();
                }
                Node *next = curr->getnext()->getnext();
                curr->setnext(next);
                if (next != NULL)
                    next->setprevious(curr);
            }
        }
    }

    void display()
    {
        cout << "list: ";
        Node *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->getdata() << " ";
            ptr = ptr->getnext();
        }
        cout << endl;
    }

    void update(int pos, int d)
    {
        Node *ptr = head;
        for (int i = 0; i < pos - 1; i++)
        {
            ptr = ptr->getnext();
        }
        ptr->setdata(d);
    }
};

int main()
{
    Node *n1 = new Node(10);
    Node *n2 = new Node(20);
    Node *n3 = new Node(30);
    Node *n4 = new Node(40);
    Node *n5 = new Node(99);

    DoublyLinkedList l1;
    l1.append(n1);
    l1.append(n2);
    l1.append(n3);
    l1.append(n4);
    l1.display();

    cout << l1.count() << endl;

    l1.insert(3, n5);
    l1.display();

    l1.deletenode(1);
    l1.display();

    l1.update(1, 79);
    l1.display();

    return 0;
}
