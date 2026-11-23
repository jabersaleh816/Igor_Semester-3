// Full name: Saleh Jaber
// ID: 214321515

#include <iostream>

using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;
};

class BinaryTree
{
public:
    Node* root;
    int count;

    BinaryTree() : root(nullptr), count(0) {}

    //   O(n)
    void preorder(Node* x)
    {
        if (x == nullptr)
            return;

        cout << x->key << ' ';
        preorder(x->left);
        preorder(x->right);
    }

    //  O(n)
    void inorder(Node* x)
    {
        if (x == nullptr)
            return;

        inorder(x->left);
        cout << x->key << ' ';
        inorder(x->right);
    }

    //  O(n)
    void postorder(Node* x)
    {
        if (x == nullptr)
            return;

        postorder(x->left);
        postorder(x->right);
        cout << x->key << ' ';
    }
};

// O(n)
void printPaths(Node* root, int path[], int pathLength)
{
    if (root == nullptr)
        return;

    path[pathLength] = root->key;
    pathLength++;

    if (root->left == nullptr && root->right == nullptr)
    {
        for (int i = 0; i < pathLength; i++)
            cout << path[i] << ' ';
        cout << '\n';
        return;
    }

    printPaths(root->left, path, pathLength);
    printPaths(root->right, path, pathLength);
}
// O(n)
int kthInorderHelper(Node* root, int k, int& visited)
{
    if (root == nullptr)
        return 0;

    int result = kthInorderHelper(root->left, k, visited);
    if (visited == k)
        return result;

    visited++;
    if (visited == k)
        return root->key;

    return kthInorderHelper(root->right, k, visited);
}

// O(n)
int kthInorder(Node* root, int k)
{
    int visited = 0;
    return kthInorderHelper(root, k, visited);
}

// O(n).
int setSubtreeSizes(Node* root)
{
    if (root == nullptr)
        return 0;

    int leftSize = setSubtreeSizes(root->left);
    int rightSize = setSubtreeSizes(root->right);
    root->key = leftSize + rightSize + 1;
    return root->key;
}

// O(n).
void deleteTree(Node* root)
{
    if (root == nullptr)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// O(n)
int main()
{
    BinaryTree tree;

    tree.root = new Node{10, nullptr, nullptr};
    tree.root->left = new Node{5, nullptr, nullptr};
    tree.root->right = new Node{8, nullptr, nullptr};
    tree.root->left->left = new Node{3, nullptr, nullptr};
    tree.root->left->right = new Node{12, nullptr, nullptr};
    tree.root->right->left = new Node{7, nullptr, nullptr};
    tree.root->right->right = new Node{2, nullptr, nullptr};
    tree.root->left->right->left = new Node{6, nullptr, nullptr};
    tree.count = 8;

    cout << "preorder: ";
    tree.preorder(tree.root);
    cout << '\n';

    cout << "inorder: ";
    tree.inorder(tree.root);
    cout << '\n';

    cout << "postorder: ";
    tree.postorder(tree.root);
    cout << '\n';

    int path[8];
    cout << "root-to-leaf paths:\n";
    printPaths(tree.root, path, 0);

    cout << "4th inorder: " << kthInorder(tree.root, 4) << '\n';
    cout << "6th inorder: " << kthInorder(tree.root, 6) << '\n';

    setSubtreeSizes(tree.root);
    cout << "preorder after subtree sizes: ";
    tree.preorder(tree.root);
    cout << '\n';

    deleteTree(tree.root);
    tree.root = nullptr;
    return 0;
}