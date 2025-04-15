#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class BST_Array
{
    int tree[100];
    int height[100];

public:
    BST_Array()
    {
        for (int i = 0; i < 100; i++)
        {
            tree[i] = -1;
            height[i] = 0;
        }
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
            insert(value, 2 * index); // Left child
        else
            insert(value, 2 * index + 1); // Right child
    }

    void BFS()
    {
        if (tree[1] == -1)
        {
            cout << "Tree is empty.\n";
            return;
        }
        queue<int> q;
        q.push(1);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            if (node < 100 && tree[node] != -1)
            {
                cout << tree[node] << " ";
                q.push(2 * node);     // Left child
                q.push(2 * node + 1); // Right child
            }
        }
        cout << "\n";
    }

    void DFS(int index = 1)
    {
        if (index >= 100 || tree[index] == -1)
            return;
        cout << tree[index] << " "; // Visit the node
        DFS(2 * index);             // Left child
        DFS(2 * index + 1);         // Right child
    }

    void inorder(int index = 1)
    {
        if (index >= 100 || tree[index] == -1)
            return;
        inorder(2 * index);         // Left child
        cout << tree[index] << " "; // Visit the node
        inorder(2 * index + 1);     // Right child
    }
};

int main()
{
    BST_Array bstArr;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int val : values)
    {
        bstArr.insert(val);
    }

    cout << "BFS (Breadth-First Search):\n";
    bstArr.BFS();

    cout << "DFS (Depth-First Search):\n";
    bstArr.DFS();

    cout << "Inorder Traversal:\n";
    bstArr.inorder();
    return 0;
}
