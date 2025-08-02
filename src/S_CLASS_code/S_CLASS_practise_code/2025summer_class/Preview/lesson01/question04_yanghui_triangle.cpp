//
// Created by Emma on 2025/7/10.
//
#include<iostream>
using namespace std;

int a[110][110];

int main() {
    int n;
    cin >> n;
    a[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        a[i][1] = 1;
        a[i][i] = 1;
        for (int j = 2; j < i; j++) {
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}