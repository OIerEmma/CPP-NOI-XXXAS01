//
// Created by Emme.Kwok on 2026/5/30.
//
#include<iostream>
#include<cmath>
using namespace std;

int a[101][101], b[101][101], mins, mini, minj;
int m, n, r, s;

void read(int k[101][101], int p, int q) {
    for (int i = 0; i < p; i++)
        for (int j = 0; j < q; j++)
            cin >> k[i][j];
}

int f(int i, int j) {
    int sum = 0;
    for (int p = 0; p < r; p++)
        for (int q = 0; q < s; q++)
            sum += abs(a[p + i][q + j] - b[p][q]);
    return sum;
}

int main() {
    cin >> m >> n;
    read(a, m, n);
    cin >> r >> s;
    read(b, r, s);
    mins = 100 * m * n;
    for (int i = 0; i <= m - r; i++)
        for (int j = 0; j <= n - s; j++) {
            int t = f(i, j);
            if (t < mins) mins = t, mini = i, minj = j;
        }
    for (int i = 0; i < r; i++) {
        cout << a[i + mini][minj];
        for (int j = 1; j < s; j++) cout << " " << a[i + mini][j + minj];
        cout << endl;
    }
    return 0;
}