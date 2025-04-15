#include <iostream>
#include <algorithm> // for max
using namespace std;

class AVL_Array
{
    int tree[100];
    int height[100]; // To keep track of the heights of nodes

public:
    AVL_Array()
    {
        for (int i = 0; i < 100; i++)
        {
            tree[i] = -1;
            height[i] = 0;
        }
    }

    int getHeight(int index)
    {
        return height[index];
    }

    int getBalanceFactor(int index)
    {
        if (index >= 100 || tree[index] == -1)
            return 0;
        return getHeight(2 * index) - getHeight(2 * index + 1);
    }

    int rotateRight(int index)
    {
        int leftChild = 2 * index;
        if (leftChild >= 100 || tree[leftChild] == -1)
            return index;
        swap(tree[index], tree[leftChild]);
        height[index] = max(getHeight(2 * index), getHeight(2 * index + 1)) + 1;
        height[leftChild] = max(getHeight(2 * leftChild), getHeight(2 * leftChild + 1)) + 1;
        return leftChild;
    }

    int rotateLeft(int index)
    {
        int rightChild = 2 * index + 1;
        if (rightChild >= 100 || tree[rightChild] == -1)
            return index;
        swap(tree[index], tree[rightChild]);
        height[index] = max(getHeight(2 * index), getHeight(2 * index + 1)) + 1;
        height[rightChild] = max(getHeight(2 * rightChild), getHeight(2 * rightChild + 1)) + 1;
        return rightChild;
    }

    int balance(int index)
    {
        int balanceFactor = getBalanceFactor(index);
        if (balanceFactor > 1)
        {
            if (getBalanceFactor(2 * index) < 0)
                return rotateLeft(2 * index);
            return rotateRight(index);
        }
        else if (balanceFactor < -1)
        {
            if (getBalanceFactor(2 * index + 1) > 0)
                return rotateRight(2 * index + 1);
            return rotateLeft(index);
        }
        return index;
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
        height[index] = max(getHeight(2 * index), getHeight(2 * index + 1)) + 1;
        index = balance(index);
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
    AVL_Array avlArr;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int val : values)
        avlArr.insert(val);

    cout << "AVL Tree (Array):\n";
    cout << "Inorder: ";
    avlArr.inorder();
    cout << "\n";
    cout << "Preorder: ";
    avlArr.preorder();
    cout << "\n";
    cout << "Postorder: ";
    avlArr.postorder();
    cout << "\n";

    return 0;
}
