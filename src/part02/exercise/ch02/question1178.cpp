//
// Created by Emma on 2025/4/5.
//
#include<iostream>
using namespace std;

int main() {
    int n, k;
    scanf("%d", &n);
    int a[n];
    string b[n];
    for (int i = 0; i < n; i++) {
        cin >> b[i] >> a[i];
    }
    for (int i = 0; i < n; i++) {
        k = i;
        for (int j = i; j < n; j++) {
            if (a[j] > a[k]) {
                k = j;
            }
        }
        if (k != i) {
            swap(a[i], a[k]);
            swap(b[i], b[k]);
        }
        if (i >= 1 && a[i] == a[i - 1]) {
            if (b[i] < b[i - 1]) {
                swap(b[i], b[i - 1]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << b[i] << " " << a[i] << endl;
    }
    return 0;
}
