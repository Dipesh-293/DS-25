#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

// Insert at beginning
void insertBeg(int x) {
    Node* temp = new Node{x, NULL, head};
    if (head) head->prev = temp;
    head = temp;
}

// Insert at end
void insertEnd(int x) {
    Node* temp = new Node{x, NULL, NULL};
    if (!head) {
        head = temp;
        return;
    }
    Node* t = head;
    while (t->next) t = t->next;
    t->next = temp;
    temp->prev = t;
}

// Insert before specific value
void insertBefore(int key, int x) {
    if (!head) return;

    if (head->data == key) {
        insertBeg(x);
        return;
    }

    Node* t = head;
    while (t && t->data != key) t = t->next;

    if (t) {
        Node* temp = new Node{x, t->prev, t};
        t->prev->next = temp;
        t->prev = temp;
    }
}

// Insert after specific value
void insertAfter(int key, int x) {
    Node* t = head;
    while (t && t->data != key) t = t->next;

    if (t) {
        Node* temp = new Node{x, t, t->next};
        if (t->next) t->next->prev = temp;
        t->next = temp;
    }
}

// Delete node containing key
void deleteNode(int key) {
    if (!head) return;

    Node* t = head;

    while (t && t->data != key) t = t->next;

    if (!t) return;

    if (t == head)
        head = head->next;

    if (t->prev)
        t->prev->next = t->next;

    if (t->next)
        t->next->prev = t->prev;

    delete t;
}

// Search
int search(int key) {
    Node* t = head;
    int pos = 1;
    while (t) {
        if (t->data == key) return pos;
        t = t->next;
        pos++;
    }
    return -1;
}

// Display
void display() {
    Node* t = head;
    while (t) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

int main() {
    int ch, x, key;

    while (true) {
        cout << "\nDLL MENU\n1.Insert Beg\n2.Insert End\n3.Insert Before\n4.Insert After\n5.Delete\n6.Search\n7.Display\n8.Exit\n";
        cin >> ch;

        switch (ch) {
            case 1: cin >> x; insertBeg(x); break;
            case 2: cin >> x; insertEnd(x); break;
            case 3: cin >> key >> x; insertBefore(key, x); break;
            case 4: cin >> key >> x; insertAfter(key, x); break;
            case 5: cin >> key; deleteNode(key); break;
            case 6: cin >> key; cout << search(key) << endl; break;
            case 7: display(); break;
            case 8: return 0;
        }
    }
}
