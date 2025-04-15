#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(NULL) {}
};

class LinkedList
{
public:
    Node *head;
    LinkedList() : head(NULL) {}

    void append(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
            head = newNode;
        else
        {
            Node *temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void print()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Linear Search
    int linearSearch(int key)
    {
        Node *temp = head;
        int index = 0;
        while (temp)
        {
            if (temp->data == key)
                return index;
            temp = temp->next;
            index++;
        }
        return -1; // Not found
    }

    // Helper: Get index from a node to target
    int getIndexFrom(Node *start, Node *target)
    {
        int idx = 0;
        while (start != target)
        {
            start = start->next;
            idx++;
        }
        return idx;
    }

    // Helper: Get Middle Node
    Node *getMiddle(Node *start, Node *end)
    {
        if (!start)
            return NULL;
        Node *slow = start, *fast = start->next;
        while (fast != end)
        {
            fast = fast->next;
            if (fast != end)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        return slow;
    }

    // Binary Search (only works correctly if list is sorted)
    int binarySearch(int key)
    {
        Node *start = head;
        Node *end = NULL;
        int index = 0;

        while (start != end)
        {
            Node *mid = getMiddle(start, end);
            if (!mid)
                return -1;

            if (mid->data == key)
                return index + getIndexFrom(start, mid);
            else if (mid->data < key)
            {
                index += getIndexFrom(start, mid) + 1;
                start = mid->next;
            }
            else
            {
                end = mid;
            }
        }

        return -1; // Not found
    }
};

int main()
{
    LinkedList list;

    // Sorted list for binary search
    int arr[] = {3, 7, 10, 14, 18, 25};
    for (int val : arr)
        list.append(val);

    cout << "Linked List: ";
    list.print();

    // Linear Search
    int key1 = 14;
    int result1 = list.linearSearch(key1);
    cout << "Linear Search for " << key1 << ": ";
    if (result1 != -1)
        cout << "Found at index " << result1 << endl;
    else
        cout << "Not found\n";

    // Binary Search
    int key2 = 18;
    int result2 = list.binarySearch(key2);
    cout << "Binary Search for " << key2 << ": ";
    if (result2 != -1)
        cout << "Found at index " << result2 << endl;
    else
        cout << "Not found\n";

    return 0;
}
