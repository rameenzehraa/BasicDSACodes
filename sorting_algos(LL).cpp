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

    void bubbleSort()
    {
        if (!head || !head->next)
            return;
        bool swapped;
        do
        {
            swapped = false;
            Node *temp = head;
            while (temp->next)
            {
                if (temp->data > temp->next->data)
                {
                    swap(temp->data, temp->next->data);
                    swapped = true;
                }
                temp = temp->next;
            }
        } while (swapped);
    }

    void insertionSort()
    {
        Node *sorted = NULL;
        Node *current = head;
        while (current)
        {
            Node *next = current->next;
            if (!sorted || sorted->data > current->data)
            {
                current->next = sorted;
                sorted = current;
            }
            else
            {
                Node *temp = sorted;
                while (temp->next && temp->next->data < current->data)
                    temp = temp->next;
                current->next = temp->next;
                temp->next = current;
            }
            current = next;
        }
        head = sorted;
    }

    Node *merge(Node *a, Node *b)
    {
        if (!a)
            return b;
        if (!b)
            return a;
        if (a->data < b->data)
        {
            a->next = merge(a->next, b);
            return a;
        }
        else
        {
            b->next = merge(a, b->next);
            return b;
        }
    }

    Node *mergeSort(Node *h)
    {
        if (!h || !h->next)
            return h;
        Node *slow = h, *fast = h->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node *mid = slow->next;
        slow->next = NULL;
        return merge(mergeSort(h), mergeSort(mid));
    }

    void applyMergeSort()
    {
        head = mergeSort(head);
    }

    void selectionSort()
    {
        Node *temp = head;
        while (temp)
        {
            Node *minNode = temp;
            Node *r = temp->next;
            while (r)
            {
                if (r->data < minNode->data)
                    minNode = r;
                r = r->next;
            }
            swap(temp->data, minNode->data);
            temp = temp->next;
        }
    }

    Node *getTail(Node *start)
    {
        while (start && start->next)
            start = start->next;
        return start;
    }

    Node *partition(Node *head, Node *end, Node **newHead, Node **newEnd)
    {
        Node *pivot = end;
        Node *prev = NULL, *cur = head, *tail = pivot;

        while (cur != pivot)
        {
            if (cur->data < pivot->data)
            {
                if (!(*newHead))
                    *newHead = cur;
                prev = cur;
                cur = cur->next;
            }
            else
            {
                if (prev)
                    prev->next = cur->next;
                Node *tmp = cur->next;
                cur->next = NULL;
                tail->next = cur;
                tail = cur;
                cur = tmp;
            }
        }

        if (!(*newHead))
            *newHead = pivot;
        *newEnd = tail;
        return pivot;
    }

    Node *quickSortRec(Node *head, Node *end)
    {
        if (!head || head == end)
            return head;

        Node *newHead = NULL, *newEnd = NULL;
        Node *pivot = partition(head, end, &newHead, &newEnd);

        if (newHead != pivot)
        {
            Node *temp = newHead;
            while (temp->next != pivot)
                temp = temp->next;
            temp->next = NULL;

            newHead = quickSortRec(newHead, temp);

            temp = getTail(newHead);
            temp->next = pivot;
        }

        pivot->next = quickSortRec(pivot->next, newEnd);
        return newHead;
    }

    void applyQuickSort()
    {
        head = quickSortRec(head, getTail(head));
    }

    void heapify(Node *root, int n, int i)
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        Node **nodes = new Node *[n];
        Node *temp = root;
        for (int j = 0; j < n; j++)
        {
            nodes[j] = temp;
            temp = temp->next;
        }

        if (l < n && nodes[l]->data > nodes[largest]->data)
            largest = l;
        if (r < n && nodes[r]->data > nodes[largest]->data)
            largest = r;

        if (largest != i)
        {
            swap(nodes[i]->data, nodes[largest]->data);
            heapify(root, n, largest);
        }
    }

    void heapSort()
    {
        int n = 0;
        Node *temp = head;
        while (temp)
        {
            n++;
            temp = temp->next;
        }

        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(head, n, i);

        for (int i = n - 1; i > 0; i--)
        {
            Node *temp = head;
            for (int j = 0; j < i; j++)
                temp = temp->next;
            swap(head->data, temp->data);
            heapify(head, i, 0);
        }
    }
};

int main()
{
    int arr[] = {29, 10, 14, 37, 13, 7};
    const int n = sizeof(arr) / sizeof(arr[0]);

    LinkedList l1, l2, l3, l4, l5, l6;
    for (int i = 0; i < n; i++)
    {
        l1.append(arr[i]);
        l2.append(arr[i]);
        l3.append(arr[i]);
        l4.append(arr[i]);
        l5.append(arr[i]);
        l6.append(arr[i]);
    }

    cout << "Original:\n";
    l1.print();

    cout << "\nBubble Sort:\n";
    l1.bubbleSort();
    l1.print();
    cout << "\nInsertion Sort:\n";
    l2.insertionSort();
    l2.print();
    cout << "\nMerge Sort:\n";
    l3.applyMergeSort();
    l3.print();
    cout << "\nSelection Sort:\n";
    l4.selectionSort();
    l4.print();
    cout << "\nQuick Sort:\n";
    l5.applyQuickSort();
    l5.print();
    cout << "\nHeap Sort:\n";
    l6.heapSort();
    l6.print();

    return 0;
}
