//
// Created by Emma on 2025/2/11.
//
#include<iostream>
using namespace std;

int main() {
    int m, n, num, reject = 0;
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        m -= num;
        if (m < 0) {
            m += num;
            reject++;
        }
    }
    cout << reject << endl;
    return 0;
}
