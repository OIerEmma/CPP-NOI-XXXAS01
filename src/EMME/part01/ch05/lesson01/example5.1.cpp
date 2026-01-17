//
// Created by Emma on 2025/1/12.
//
#include<iostream>
using namespace std;
int a[100];
int main() {
    int x, n = 0;
    while (scanf("%d", &x) == 1) {
        a[n++] = x;
    }
    for (int i = n - 1; i >= 1; i--) {
        cout << a[i] << " " ;
    }
    cout << a[0] << endl;
    return 0;
}
