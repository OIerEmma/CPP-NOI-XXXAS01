//
// Created by Emme.Kwok on 2026/1/24.
//
#include<iostream>
using namespace std;

const int maxn = 7;
int a[maxn][maxn];

int main() {
    int n, m;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            cin >> a[i][j];
        }
    }
    cin >> n >> m;
    for (int i = 1; i <= 5; i++) {
        swap(a[n][i], a[m][i]);
    }
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}