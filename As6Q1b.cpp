#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at beginning
void insertBeg(int x) {
    Node* temp = new Node{x, NULL};

    if (!head) {
        head = temp;
        temp->next = head;
        return;
    }

    Node* last = head;
    while (last->next != head) last = last->next;

    temp->next = head;
    last->next = temp;
    head = temp;
}

// Insert at end
void insertEnd(int x) {
    Node* temp = new Node{x, NULL};

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

// Insert after key
void insertAfter(int key, int x) {
    if (!head) return;

    Node* t = head;
    do {
        if (t->data == key) {
            Node* temp = new Node{x, t->next};
            t->next = temp;
            return;
        }
        t = t->next;
    } while (t != head);
}

// Insert before key
void insertBefore(int key, int x) {
    if (!head) return;

    Node* t = head;
    Node* prev = NULL;

    do {
        if (t->data == key) {
            if (t == head) { 
                insertBeg(x);
                return;
            }
            Node* temp = new Node{x, t};
            prev->next = temp;
            return;
        }
        prev = t;
        t = t->next;
    } while (t != head);
}

// Delete key
void deleteNode(int key) {
    if (!head) return;

    Node* curr = head;
    Node* prev = NULL;

    // Find last node
    Node* last = head;
    while (last->next != head) last = last->next;

    // Deleting head
    if (head->data == key) {
        if (head->next == head) { 
            delete head;
            head = NULL;
            return;
        }
        last->next = head->next;
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Middle or last node
    do {
        if (curr->data == key) {
            prev->next = curr->next;
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);
}

// Search
int search(int key) {
    if (!head) return -1;

    Node* t = head;
    int pos = 1;

    do {
        if (t->data == key) return pos;
        t = t->next;
        pos++;
    } while (t != head);

    return -1;
}

// Display
void display() {
    if (!head) return;

    Node* t = head;
    do {
        cout << t->data << " ";
        t = t->next;
    } while (t != head);
    cout << endl;
}

int main() {
    int ch, x, key;
    while (true) {
        cout << "\nCLL MENU\n1.Insert Beg\n2.Insert End\n3.Insert Before\n4.Insert After\n5.Delete\n6.Search\n7.Display\n8.Exit\n";
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
