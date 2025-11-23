#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
    vector<int> heap;

    void heapifyUp(int i) {
        while (i > 0) {
            int p = (i - 1) / 2;
            if (heap[p] < heap[i]) {
                swap(heap[p], heap[i]);
                i = p;
            } else break;
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();
        while (true) {
            int l = 2*i+1, r = 2*i+2, largest = i;
            if (l < n && heap[l] > heap[largest]) largest = l;
            if (r < n && heap[r] > heap[largest]) largest = r;
            if (largest != i) {
                swap(heap[i], heap[largest]);
                i = largest;
            } else break;
        }
    }

public:
    void push(int x) {
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    }

    int pop() {
        int top = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return top;
    }

    bool empty() { return heap.empty(); }
};

int main() {
    PriorityQueue pq;
    pq.push(50);
    pq.push(30);
    pq.push(40);
    pq.push(10);

    while (!pq.empty())
        cout << pq.pop() << " ";
}
