#include<iostream>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int **a = new int *[n];
    int **b = new int *[m];
    int **c = new int *[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[m];
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        b[i] = new int[k];
        for (int j = 0; j < k; j++) {
            cin >> b[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        c[i] = new int[k];
        for (int j = 0; j < k; j++) {
            c[i][j] = 0;
            for (int g = 0; g < m; g++) {
                c[i][j] += a[i][g] * b[g][j];
            }
            printf("%d ", c[i][j]);
        }
        cout << endl;
    }
    return 0;
}
