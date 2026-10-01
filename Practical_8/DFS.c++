#include <iostream>
using namespace std;

int graph[5][5] = {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 1},
    {1, 0, 0, 0, 1},
    {0, 1, 0, 0, 0},
    {0, 1, 1, 0, 0}
};

int visited[5] = {0};
int n = 5;

void DFS(int node) {
    visited[node] = 1;

    cout << node << " ";

    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    cout << "DFS Traversal: ";

    DFS(0);

    return 0;
}
