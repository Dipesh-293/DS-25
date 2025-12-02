//Deapth First Search (DFS)

#include <iostream>
using namespace std;

void DFS(int G[][7], int start, int n)
{
    static int visited[7] = {0};
    if (visited[start] == 0)
    {
        cout << start << " ";
        visited[start] = 1;
        for (int j = 1; j < n; j++)
        {
            if (G[start][j] == 1 && visited[j] == 0)
            {
                DFS(G, j, n);
            }
        }
    }
}

int main(){
    int n, start;
    int G[7][7];
    cout << "Enter number of vertices (max 6): ";
    cin >> n;
    cout << "Enter adjacency matrix:\n";
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            cin >> G[i][j];
        }
    }
    cout << "Enter starting vertex for DFS (1 to " << n-1 << "): ";
    cin >> start;
    cout << "DFS Traversal starting from vertex " << start << ": ";
    DFS(G, start, n);
    cout << endl;
    return 0;
}