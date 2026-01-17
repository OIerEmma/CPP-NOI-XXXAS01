//
// Created by Emma on 2025/8/5.
//
#include<iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    bool flag = false;
    for (int i = n; i <= m; i++) {
        int sum = 0, num = i;
        while (num) {
            sum += num % 10 * (num % 10) * (num % 10);
            num /= 10;
        }
        if (sum == i) {
            cout << i << endl;
            flag = true;
        }
    }
    if (!flag) {
        cout << "NO" << endl;
    }
    return 0;
}