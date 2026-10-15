#include <iostream>
using namespace std;

int main() {
    int n = 5, m = 7;

    char u[7] = {'A', 'A', 'B', 'B', 'D', 'C', 'D'};
    char v[7] = {'B', 'C', 'C', 'D', 'C', 'E', 'E'};
    int w[7] = {2, 3, 1, 4, 5, 6, 7};

    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (w[j] > w[j + 1]) {
                int temp = w[j];
                w[j] = w[j + 1];
                w[j + 1] = temp;

                char tempChar = u[j];
                u[j] = u[j + 1];
                u[j + 1] = tempChar;

                tempChar = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tempChar;
            }
        }
    }

    int parent[5];

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int edges = 0, total = 0;

    for (int i = 0; i < m && edges < n - 1; i++) {
        int a = u[i] - 'A';
        int b = v[i] - 'A';

        int x = a, y = b;

        while (parent[x] != x)
            x = parent[x];

        while (parent[y] != y)
            y = parent[y];

        if (x != y) {
            cout << u[i] << " - " << v[i]
                 << " : " << w[i] << endl;

            parent[x] = y;
            total += w[i];
            edges++;
        }
    }

    if (edges != n - 1)
        cout << "Graph is disconnected";
    else
        cout << "Total cost = " << total;

    return 0;
}