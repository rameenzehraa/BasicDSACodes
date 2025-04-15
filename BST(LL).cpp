#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class BST_LinkedList
{
public:
    Node *root;

    BST_LinkedList()
    {
        root = NULL;
    }

    Node *insert(Node *root, int val)
    {
        if (!root)
            return new Node(val);
        if (val < root->data)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);
        return root;
    }

    void inorder(Node *root)
    {
        if (!root)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void preorder(Node *root)
    {
        if (!root)
            return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node *root)
    {
        if (!root)
            return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
};

int main()
{
    BST_LinkedList bst;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int val : values)
        bst.root = bst.insert(bst.root, val);

    cout << "BST (Linked List):\n";
    cout << "Inorder: ";
    bst.inorder(bst.root);
    cout << "\n";
    cout << "Preorder: ";
    bst.preorder(bst.root);
    cout << "\n";
    cout << "Postorder: ";
    bst.postorder(bst.root);
    cout << "\n";

    return 0;
}
