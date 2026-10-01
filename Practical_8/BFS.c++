#include <iostream>
using namespace std;

int main() {
    int n = 5;

    int graph[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0}
    };

    int visited[5] = {0};
    int queue[5];
    int front = 0, rear = 0;

    int start = 0;

    visited[start] = 1;
    queue[rear++] = start;

    cout << "BFS Traversal: ";

    while (front < rear) {
        int node = queue[front++];

        cout << node << " ";

        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    return 0;
}
