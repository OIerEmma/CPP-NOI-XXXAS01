//
// Created by Amy on 2025/12/6.
//
#include <iostream>
using namespace std;

int main() {
    int a[1001], n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++) {
        cout << a[i] << endl;
    }
    cout << a[1] << endl;
    return 0;
}
