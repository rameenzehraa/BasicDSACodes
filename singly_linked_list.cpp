#include <iostream>
using namespace std;

class Node
{
    int key;
    int data;
    Node *next;

public:
    Node() : key(0), data(0), next(NULL) {}
    Node(int k, int d) : key(k), data(d), next(NULL) {}

    int getkey() { return key; }
    Node *getnext() { return next; }
    int getdata() { return data; }
    void setdata(int abc) { data = abc; }
    void setnext(Node *abc) { next = abc; }
};

class SinglyLinkedList
{
    Node *head;

public:
    SinglyLinkedList() : head(NULL) {}
    SinglyLinkedList(Node *n) : head(n) {}

    Node *traverse(int k)
    {
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->getkey() == k)
            {
                return ptr;
            }
            ptr = ptr->getnext();
        }
        return NULL;
    }

    void append(Node *n)
    {
        if (traverse(n->getkey()) != NULL)
        {
            cout << "this key already exists" << endl;
            return;
        }
        else if (head == NULL)
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
        }
        cout << "Appended successfully!" << endl;
    }

    void prepend(Node *n)
    {
        if (traverse(n->getkey()) != NULL)
        {
            cout << "key already exists" << endl;
            return;
        }
        else if (head == NULL)
        {
            head = n;
            cout << "prepended successfully!" << endl;
        }
        else
        {
            n->setnext(head);
            head = n;
            cout << "prepended successfully!" << endl;
        }
    }

    void insertafter(int k, Node *n)
    {
        Node *ptr = traverse(k);
        if (ptr != NULL)
        {
            if (traverse(n->getkey()) == NULL)
            {
                n->setnext(ptr->getnext());
                ptr->setnext(n);
                cout << "added" << endl;
            }
            else
            {
                cout << "same key already exists" << endl;
            }
        }
        else
        {
            cout << "no such key found" << endl;
        }
    }

    void deletenode(int k)
    {
        if (head == NULL)
        {
            cout << "empty!" << endl;
            return;
        }
        if (head->getkey() == k)
        {
            head = head->getnext();
            return;
        }
        Node *prev = head;
        Node *curr = head->getnext();
        while (curr != NULL)
        {
            if (curr->getkey() == k)
            {
                prev->setnext(curr->getnext());
                return;
            }
            prev = curr;
            curr = curr->getnext();
        }
        cout << "no such keyy found" << endl;
    }

    void update(int k, int d)
    {
        Node *ptr = traverse(k);
        if (ptr == NULL)
        {
            cout << "node with such key not found" << endl;
        }
        else
        {
            ptr->setdata(d);
            cout << "data updated" << endl;
        }
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "list is empty" << endl;
        }
        else
        {
            Node *print = head;
            while (print != NULL)
            {
                cout << print->getdata() << ", ";
                print = print->getnext();
            }
            cout << endl;
        }
    }
};

int main()
{
    Node *node1 = new Node(1, 10);
    Node *node2 = new Node(2, 20);
    Node *node3 = new Node(3, 30);
    Node *node4 = new Node(4, 40);
    Node *node5 = new Node(5, 50);

    SinglyLinkedList sll;

    cout << "Appending nodes:" << endl;
    sll.append(node1);
    sll.append(node2);
    sll.append(node3);
    sll.display();

    cout << "Prepending node with key 0 and data 5:" << endl;
    Node *node0 = new Node(0, 5);
    sll.prepend(node0);
    sll.display();

    cout << "Inserting node with key 4 and data 40 after node with key 2:" << endl;
    sll.insertafter(2, node4);
    sll.display();

    cout << "Attempting to insert a node with an existing key (key 3):" << endl;
    Node *duplicateNode = new Node(3, 35);
    sll.insertafter(1, duplicateNode);
    sll.display();

    cout << "Updating node with key 2 to have data 25:" << endl;
    sll.update(2, 25);
    sll.display();

    cout << "Deleting node with key 3:" << endl;
    sll.deletenode(3);
    sll.display();

    cout << "Attempting to delete a node with a non-existent key (key 10):" << endl;
    sll.deletenode(10);
    sll.display();

    cout << "Attempting to prepend a node with an existing key (key 2):" << endl;
    Node *existingKeyNode = new Node(2, 15);
    sll.prepend(existingKeyNode);
    sll.display();

    while (sll.traverse(node0->getkey()) != NULL)
    {
        sll.deletenode(node0->getkey());
    }
    cout << "All nodes deleted. Final list:" << endl;
    sll.display();

    return 0;
}
