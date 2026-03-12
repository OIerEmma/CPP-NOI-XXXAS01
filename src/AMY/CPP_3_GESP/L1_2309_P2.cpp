//
// Created by Amy on 2026/2/4.
//
#include<iostream>
using namespace std;

int main() {
    int k, L, R, sum = 0;
    cin >> k >> L >> R;
    for (int i = L; i <= R; i++) {
        if (i % k == 0 || i % 10 == k) {
            sum += i;
        }
    }
    cout << sum;
    return 0;
}
