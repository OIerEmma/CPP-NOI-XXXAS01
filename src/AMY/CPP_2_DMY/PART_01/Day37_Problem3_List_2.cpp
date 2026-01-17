//
// Created by Amy on 2025/12/6.
//
#include <iostream>
using namespace std;

int main() {
    int a[1001], n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= k-1; i++) {
        cout << a[i] << endl;
    }
    for (int i = k+1;i <= n;i++)
        cout << a[i] << endl;
    cout << a[k] << endl;
    return 0;
}
