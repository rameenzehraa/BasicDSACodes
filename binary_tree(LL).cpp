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

class BinaryTreeLinkedList
{
public:
    Node *root;

    BinaryTreeLinkedList()
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
    BinaryTreeLinkedList tree;

    tree.root = tree.insert(tree.root, 10);
    tree.insert(tree.root, 5);
    tree.insert(tree.root, 15);
    tree.insert(tree.root, 3);
    tree.insert(tree.root, 7);

    cout << "Inorder: ";
    tree.inorder(tree.root);
    cout << "\nPreorder: ";
    tree.preorder(tree.root);
    cout << "\nPostorder: ";
    tree.postorder(tree.root);
    cout << endl;

    return 0;
}
