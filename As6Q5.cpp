#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};
Node* createLinearList(int arr[], int n) {
    if (n == 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* tail = head;
    for (int i = 1; i < n; ++i) {
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }
    return head;
}
Node* createCircularList(int arr[], int n) {
    if (n == 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* tail = head;
    for (int i = 1; i < n; ++i) {
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }
    tail->next = head; 
    return head;
}
bool isCircular(Node* head) {
    if (!head) return false;
    Node* cur = head->next;
    while (cur && cur != head) cur = cur->next;
    return (cur == head);
}
int main() {
    int a1[] = {2,4,6,7,5};
    Node* linear = createLinearList(a1, 5);
    cout << (isCircular(linear) ? "True\n" : "False\n"); 

    int a2[] = {10, 4, 9}; 
    Node* circular = createCircularList(a2, 3);
    cout << (isCircular(circular) ? "True\n" : "False\n"); 

    return 0;
}
