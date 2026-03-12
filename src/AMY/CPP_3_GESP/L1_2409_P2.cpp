//
// Created by Amy on 2026/1/25.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        if (x % 9 == 0 && x % 8 != 0) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}