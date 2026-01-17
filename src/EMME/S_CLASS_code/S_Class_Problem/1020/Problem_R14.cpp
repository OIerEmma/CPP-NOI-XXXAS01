//
// Created by Emma on 2025/8/11.
//
#include<iostream>
using namespace std;

int arr[4] = {0, 1, 2, 4};

int main() {
    int n;
    cin >> n;
    long long a = 1, b = 2, c = 4, d = 0;
    if (n <= 3) {
        cout << arr[n] << endl;
        return 0;
    }
    for (int i = 4; i <= n; i++) {
        d = a + b + c;
        a = b;
        b = c;
        c = d;
    }
    cout << d << endl;
    return 0;
}