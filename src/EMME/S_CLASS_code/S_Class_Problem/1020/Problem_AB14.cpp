//
// Created by Emma on 2025/8/11.
//
#include<iostream>
using namespace std;

bool a[1000001];

int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j % i == 0) {
                a[j] = !a[j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i];
    }
    return 0;
}