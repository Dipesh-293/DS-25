#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

// Insert at end 
void insertEnd(Node*& head, int x) {
    Node* temp = new Node(x);
    if (!head) {
        head = temp;
        temp->next = head;
        return;
    }
    Node* last = head;
    while (last->next != head) last = last->next;
    last->next = temp;
    temp->next = head;
}

// Display elements and repeat head at end 
void displayRepeatHead(Node* head) {
    if (!head) {
        cout << "List is empty\n";
        return;
    }
    Node* t = head;
    do {
        cout << t->data << " ";
        t = t->next;
    } while (t != head);
    cout << head->data << "\n";
}

int main() {
    Node* head = nullptr;
    insertEnd(head, 20);
    insertEnd(head, 100);
    insertEnd(head, 40);
    insertEnd(head, 80);
    insertEnd(head, 60);

    cout << "Output: ";
    displayRepeatHead(head); 
    if (head) {
        Node* cur = head->next;
        while (cur != head) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
        delete head;
    }
    return 0;
}
