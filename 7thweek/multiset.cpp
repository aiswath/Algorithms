#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    int cnt;
    int sz;
    Node *left, *right;
    Node(int key, Node *left = nullptr, Node *right = nullptr)
        : key(key), cnt(1), sz(1), left(left), right(right) {}
};

void DestroySplayTree(Node *root)
{
    if (!root)
        return;
    DestroySplayTree(root->left);
    DestroySplayTree(root->right);
    delete root;
}

int GetSize(Node *x)
{
    return x ? x->sz : 0;
}

void Resize(Node *x)
{
    if (x)
        x->sz = x->cnt + GetSize(x->left) + GetSize(x->right);
}


Node *Zig(Node *y)
{
    Node *x = y->left;
    y->left = x->right;
    x->right = y;
    Resize(y);
    Resize(x);
    return x;
}

Node *Zag(Node *x)
{
    Node *y = x->right;
    x->right = y->left;
    y->left = x;
    Resize(x);
    Resize(y);
    return y;
}

Node *Splay(Node *root, int key)
{
    if (!root)
        return nullptr;

    if (key < root->key)
    {
        if (!root->left)
            return root;
        if (key < root->left->key)
        {
            root->left->left = Splay(root->left->left, key);
            root = Zig(root);
        }
        else if (key > root->left->key)
        {
            root->left->right = Splay(root->left->right, key);
            if (root->left->right)
                root->left = Zag(root->left);
        }
        return root->left ? Zig(root) : root;
    }
    else if (key > root->key)
    {
        if (!root->right)
            return root;
        if (key > root->right->key)
        {
            root->right->right = Splay(root->right->right, key);
            root = Zag(root);
        }
        else if (key < root->right->key)
        {
            root->right->left = Splay(root->right->left, key);
            if (root->right->left)
                root->right = Zig(root->right);
        }
        return root->right ? Zag(root) : root;
    }
    else
        return root; 
}


Node *Insert(Node *root, int key)
{
    if (!root)
        return new Node(key);

    root = Splay(root, key);
    if (root->key == key)
    {
        root->cnt++;
        Resize(root);
        return root;
    }

    Node *node = new Node(key);
    if (key < root->key)
    {
        node->right = root;
        node->left = root->left;
        root->left = nullptr;
        Resize(root);
    }
    else
    {
        node->left = root;
        node->right = root->right;
        root->right = nullptr;
        Resize(root);
    }
    Resize(node);
    return node;
}

Node *Delete(Node *root, int key)
{
    if (!root)
        return nullptr;
    root = Splay(root, key);
    if (root->key != key)
        return root; 
    if (root->cnt > 1)
    {
        root->cnt--;
        Resize(root);
        return root;
    }
    Node *res;
    if (!root->left)
        res = root->right;
    else
    {
        res = Splay(root->left, key);
        res->right = root->right;
    }
    delete root;
    Resize(res);
    return res;
}

int Order(Node *root, int k)
{
    if (!root || k <= 0 || k > GetSize(root))
        return -1;
    int left_size = GetSize(root->left);
    if (k <= left_size)
        return Order(root->left, k);
    else if (k <= left_size + root->cnt)
        return root->key;
    else
        return Order(root->right, k - left_size - root->cnt);
}


int OrderOfKey(Node *root, int x)
{
    if (!root)
        return 0;
    if (x <= root->key)
        return OrderOfKey(root->left, x);
    else
        return GetSize(root->left) + root->cnt + OrderOfKey(root->right, x);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int NumTestCases;
    cin >> NumTestCases;

    while (NumTestCases--)
    {
        int queries;
        cin >> queries;
        Node *root = nullptr;

        for (int i = 0; i < queries; i++)
        {
            int query, x;
            cin >> query >> x;
            if (query == 1)
            {
                root = Insert(root, x);
            }
            else if (query == 2)
            {
                root = Delete(root, x);
            }
            else if (query == 3)
            {
                cout << Order(root, x) << "\n";
            }
            else if (query == 4)
            {
                cout << OrderOfKey(root, x) << "\n";
            }
        }
        DestroySplayTree(root);
    }
    return 0;
}
