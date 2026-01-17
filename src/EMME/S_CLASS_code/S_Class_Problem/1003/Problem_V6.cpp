//
// Created by Emma on 2025/7/2.
//
#include<iostream>
using namespace std;

int a[10][10];

int main() {
    int n, m;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> a[i][j];
        }
    }
    cin >> n >> m;
    n -= 1;
    m -= 1;
    int temp;
    for (int i = 0; i < 5; i++) {
        temp = a[n][i];
        a[n][i] = a[m][i];
        a[m][i] = temp;
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
