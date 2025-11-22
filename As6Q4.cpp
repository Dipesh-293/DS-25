#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
    Node(char c) : data(c), prev(nullptr), next(nullptr) {}
};

void insertEnd(Node*& head, char c) {
    Node* n = new Node(c);
    if (!head) {
        head = n;
        return;
    }
    Node* t = head;
    while (t->next) t = t->next;
    t->next = n;
    n->prev = t;
}

bool isPalindrome(Node* head) {
    if (!head) return true;

    Node* tail = head;
    while (tail->next) tail = tail->next;

    Node* left = head;
    Node* right = tail;

    while (left != right && left->prev != right) {
        if (left->data != right->data) return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main() {
    Node* head1 = nullptr;
    insertEnd(head1, 'a');
    insertEnd(head1, 'b');
    insertEnd(head1, 'b');
    insertEnd(head1, 'a');
    cout << (isPalindrome(head1) ? "True\n" : "False\n"); 

    Node* head2 = nullptr;
    insertEnd(head2, 'r');
    insertEnd(head2, 'a');
    insertEnd(head2, 'd');
    cout << (isPalindrome(head2) ? "True\n" : "False\n");

    return 0;
}
