
//Breadth First Search (BFS)

#include <iostream>
using namespace std;

void bfs(int graph[][10], int start, int n) {
    bool visited[10] = {false};
    int queue[10];
    int front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    cout << "BFS Traversal starting from vertex " << start << ": ";

    while (front < rear) {
        int current = queue[front++];
        cout << current << " ";

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    cout << endl;
}

int main(){
    int n, start;
    int graph[10][10];
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter adjacency matrix:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }
    cout << "Enter starting vertex for BFS (0 to " << n-1 << "): ";
    cin >> start;
    bfs(graph, start, n);
    return 0;
}
