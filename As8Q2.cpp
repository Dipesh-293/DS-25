#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int v) { data = v; left = right = NULL; }
};

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data) root->left = insert(root->left, key);
    else if (key > root->data) root->right = insert(root->right, key);
    return root;
}

// (a) SEARCH Recursive
Node* searchRec(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return searchRec(root->left, key);
    return searchRec(root->right, key);
}

// (a) SEARCH Non-Recursive
Node* searchNonRec(Node* root, int key) {
    while (root) {
        if (root->data == key) return root;
        root = (key < root->data) ? root->left : root->right;
    }
    return NULL;
}

// (b) Maximum element
Node* maxNode(Node* root) {
    while (root->right) root = root->right;
    return root;
}

// (c) Minimum element
Node* minNode(Node* root) {
    while (root->left) root = root->left;
    return root;
}

// (d) Inorder Successor
Node* inorderSuccessor(Node* root, Node* target) {
    if (target->right) return minNode(target->right);

    Node* succ = NULL;
    while (root) {
        if (target->data < root->data) {
            succ = root;
            root = root->left;
        } else if (target->data > root->data) {
            root = root->right;
        } else break;
    }
    return succ;
}

// (e) Inorder Predecessor
Node* inorderPredecessor(Node* root, Node* target) {
    if (target->left) return maxNode(target->left);

    Node* pred = NULL;
    while (root) {
        if (target->data > root->data) {
            pred = root;
            root = root->right;
        } else if (target->data < root->data) {
            root = root->left;
        } else break;
    }
    return pred;
}

int main() {
    Node* root = NULL;
    int arr[] = {20, 10, 30, 5, 15, 25, 40};
    for (int x : arr) root = insert(root, x);

    Node* t = searchRec(root, 10);
    cout << "Search(10) = " << (t ? "Found" : "Not Found") << endl;

    cout << "Max = " << maxNode(root)->data << endl;
    cout << "Min = " << minNode(root)->data << endl;

    cout << "Successor of 10 = " << inorderSuccessor(root, t)->data << endl;
    cout << "Predecessor of 10 = " << inorderPredecessor(root, t)->data << endl;
}
