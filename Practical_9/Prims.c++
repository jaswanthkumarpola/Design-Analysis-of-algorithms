
#include <iostream>
using namespace std;

int main() {
    int n = 5, m = 7;

    char u[7] = {'A', 'A', 'B', 'B', 'B', 'C', 'D'};
    char v[7] = {'B', 'D', 'C', 'D', 'E', 'E', 'E'};
    int w[7] = {2, 6, 3, 8, 5, 7, 9};

    int graph[5][5] = {0};

    for (int i = 0; i < m; i++) {
        int a = u[i] - 'A';
        int b = v[i] - 'A';

        graph[a][b] = w[i];
        graph[b][a] = w[i];
    }

    int selected[5] = {0};
    int edges = 0, total = 0;

    selected[0] = 1;

    while (edges < n - 1) {
        int min = 999999, x = -1, y = -1;

        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && graph[i][j] != 0 &&
                        graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        if (x == -1) {
            cout << "Graph is disconnected";
            return 0;
        }

        cout << char(x + 'A') << " - "
             << char(y + 'A') << " : " << min << endl;

        selected[y] = 1;
        total += min;
        edges++;
    }

    cout << "Total cost = " << total;

    return 0;
}
