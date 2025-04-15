#include <iostream>
using namespace std;

class BST_Array
{
    int tree[100];

public:
    BST_Array()
    {
        for (int i = 0; i < 100; i++)
            tree[i] = -1;
    }

    void insert(int value, int index = 1)
    {
        if (index >= 100)
        {
            cout << "Tree overflow\n";
            return;
        }

        if (tree[index] == -1)
            tree[index] = value;
        else if (value < tree[index])
            insert(value, 2 * index);
        else
            insert(value, 2 * index + 1);
    }

    void inorder(int index = 1)
    {
        if (index >= 100 || tree[index] == -1)
            return;
        inorder(2 * index);
        cout << tree[index] << " ";
        inorder(2 * index + 1);
    }

    void preorder(int index = 1)
    {
        if (index >= 100 || tree[index] == -1)
            return;
        cout << tree[index] << " ";
        preorder(2 * index);
        preorder(2 * index + 1);
    }

    void postorder(int index = 1)
    {
        if (index >= 100 || tree[index] == -1)
            return;
        postorder(2 * index);
        postorder(2 * index + 1);
        cout << tree[index] << " ";
    }
};

int main()
{
    BST_Array bstArr;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int val : values)
        bstArr.insert(val);

    cout << "BST (Array):\n";
    cout << "Inorder: ";
    bstArr.inorder();
    cout << "\n";
    cout << "Preorder: ";
    bstArr.preorder();
    cout << "\n";
    cout << "Postorder: ";
    bstArr.postorder();
    cout << "\n";

    return 0;
}
