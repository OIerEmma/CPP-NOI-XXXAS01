//
// Created by Emma on 2025/1/12.
//
#include<iostream>
using namespace std;
const int n = 10;
int a[n + 1];

int main() {
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m - 1; i++) {
        for (int j = 1; j <= m - i; j++) {
            if (a[j] < a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << a[i] << endl;
    }
    return 0;
}
