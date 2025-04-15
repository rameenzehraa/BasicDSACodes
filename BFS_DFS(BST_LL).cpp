#include <iostream>
#include <queue>
#include <stack>
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

    Node *insert(Node *node, int value)
    {
        if (node == NULL)
            return new Node(value);
        if (value < node->data)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);
        return node;
    }

    void insert(int value)
    {
        root = insert(root, value);
    }

    void BFS()
    {
        if (!root)
        {
            cout << "Tree is empty.\n";
            return;
        }
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();
            cout << node->data << " ";
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        cout << "\n";
    }

    void DFS(Node *node)
    {
        if (node == NULL)
            return;
        cout << node->data << " "; // Visit the node
        DFS(node->left);           // Left child
        DFS(node->right);          // Right child
    }

    void DFS()
    {
        DFS(root);
        cout << "\n";
    }

    void inorder(Node *node)
    {
        if (node == NULL)
            return;
        inorder(node->left);       // Left child
        cout << node->data << " "; // Visit the node
        inorder(node->right);      // Right child
    }

    void inorder()
    {
        inorder(root);
        cout << "\n";
    }
};

int main()
{
    BST_LinkedList bstLL;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int val : values)
    {
        bstLL.insert(val);
    }

    cout << "BFS (Breadth-First Search):\n";
    bstLL.BFS();

    cout << "DFS (Depth-First Search):\n";
    bstLL.DFS();

    cout << "Inorder Traversal:\n";
    bstLL.inorder();
    return 0;
}
