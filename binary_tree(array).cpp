#include <iostream>
using namespace std;

class BinaryTreeArray
{
    int tree[100];
    int size;

public:
    BinaryTreeArray()
    {
        for (int i = 0; i < 100; i++)
            tree[i] = -1;
        size = 100;
    }

    void insert(int value, int index)
    {
        if (index < size)
            tree[index] = value;
        else
            cout << "Index out of bounds\n";
    }

    void display()
    {
        cout << "Binary Tree (Array): ";
        for (int i = 1; i < size; i++)
        {
            if (tree[i] != -1)
                cout << tree[i] << " ";
        }
        cout << endl;
    }

    void inorder(int index)
    {
        if (index >= size || tree[index] == -1)
            return;
        inorder(2 * index);
        cout << tree[index] << " ";
        inorder(2 * index + 1);
    }

    void preorder(int index)
    {
        if (index >= size || tree[index] == -1)
            return;
        cout << tree[index] << " ";
        preorder(2 * index);
        preorder(2 * index + 1);
    }

    void postorder(int index)
    {
        if (index >= size || tree[index] == -1)
            return;
        postorder(2 * index);
        postorder(2 * index + 1);
        cout << tree[index] << " ";
    }
};

int main()
{
    BinaryTreeArray tree;

    tree.insert(1, 1);
    tree.insert(2, 2);
    tree.insert(3, 3);
    tree.insert(4, 4);
    tree.insert(5, 5);

    tree.display();

    cout << "Inorder: ";
    tree.inorder(1);
    cout << "\nPreorder: ";
    tree.preorder(1);
    cout << "\nPostorder: ";
    tree.postorder(1);
    cout << endl;

    return 0;
}
