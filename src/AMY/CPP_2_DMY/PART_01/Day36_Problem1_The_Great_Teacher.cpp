//
// Created by Amy on 2025/10/22.
//
#include<iostream>
using namespace std;

int main() {
    int n;
    int a[1001];
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] < 80)
            a[i] = 80;
    }
    for (int i = n; i >= 1; i--)
        cout << a[i] << endl;
    return 0;
}
