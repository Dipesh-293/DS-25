#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int v) : data(v), prev(nullptr), next(nullptr) {}
};

struct CNode {
    int data;
    CNode* next;
    CNode(int v) : data(v), next(nullptr) {}
};

void dllInsertEnd(DNode*& head, int x) {
    DNode* n = new DNode(x);
    if (!head) {
        head = n;
        return;
    }
    DNode* t = head;
    while (t->next) t = t->next;
    t->next = n;
    n->prev = t;
}

int sizeDLL(DNode* head) {
    int cnt = 0;
    while (head) {
        cnt++;
        head = head->next;
    }
    return cnt;
}

void cllInsertEnd(CNode*& head, int x) {
    CNode* n = new CNode(x);
    if (!head) {
        head = n;
        n->next = head;
        return;
    }
    CNode* t = head;
    while (t->next != head) t = t->next;
    t->next = n;
    n->next = head;
}

int sizeCLL(CNode* head) {
    if (!head) return 0;
    int cnt = 0;
    CNode* t = head;
    do {
        cnt++;
        t = t->next;
    } while (t != head);
    return cnt;
}

int main() {
    DNode* dhead = nullptr;
    dllInsertEnd(dhead, 1);
    dllInsertEnd(dhead, 2);
    dllInsertEnd(dhead, 3);
    cout << "DLL size: " << sizeDLL(dhead) << "\n"; 

    CNode* chead = nullptr;
    cllInsertEnd(chead, 10);
    cllInsertEnd(chead, 20);
    cllInsertEnd(chead, 30);
    cout << "CLL size: " << sizeCLL(chead) << "\n"; 

    return 0;
}
