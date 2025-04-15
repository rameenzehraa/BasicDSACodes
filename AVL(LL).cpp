#include <iostream>
#include <algorithm> // for max
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    int height;

    Node(int val)
    {
        data = val;
        left = right = NULL;
        height = 1;
    }
};

class AVL_LinkedList
{
public:
    Node *root;

    AVL_LinkedList()
    {
        root = NULL;
    }

    int getHeight(Node *node)
    {
        return node ? node->height : 0;
    }

    int getBalance(Node *node)
    {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    Node *rotateRight(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    Node *rotateLeft(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    Node *insert(Node *node, int value)
    {
        if (!node)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        else
            return node;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);

        if (balance > 1 && value < node->left->data)
            return rotateRight(node);

        if (balance < -1 && value > node->right->data)
            return rotateLeft(node);

        if (balance > 1 && value > node->left->data)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && value < node->right->data)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    void inorder(Node *node)
    {
        if (!node)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node *node)
    {
        if (!node)
            return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node *node)
    {
        if (!node)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    void insert(int value)
    {
        root = insert(root, value);
    }
};

int main()
{
    AVL_LinkedList avlLL;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int val : values)
        avlLL.insert(val);

    cout << "AVL Tree (Linked List):\n";
    cout << "Inorder: ";
    avlLL.inorder(avlLL.root);
    cout << "\n";
    cout << "Preorder: ";
    avlLL.preorder(avlLL.root);
    cout << "\n";
    cout << "Postorder: ";
    avlLL.postorder(avlLL.root);
    cout << "\n";

    return 0;
}
