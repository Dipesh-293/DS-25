#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int v) { data = v; left = right = NULL; }
};

bool isBSTUtil(Node* root, long minv, long maxv) {
    if (!root) return true;
    if (root->data <= minv || root->data >= maxv) return false;
    return isBSTUtil(root->left, minv, root->data) &&
           isBSTUtil(root->right, root->data, maxv);
}

bool isBST(Node* root) {
    return isBSTUtil(root, LONG_MIN, LONG_MAX);
}

int main() {
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);

    cout << (isBST(root) ? "YES BST" : "NO") << endl;
}
