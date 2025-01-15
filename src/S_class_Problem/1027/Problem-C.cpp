//
// Created by Emma on 2025/1/15.
//
#include<iostream>
using namespace std;

int main() {
    int n, x, y;
    double eat, remain;
    cin >> n >> x >> y;
    if(n == 0 || x == 0) {
        cout << 0 << endl;
    } else if(y == 0) {
        cout << n << endl;
    } else {
        eat = y * 1.0 / x;
        remain = n - eat;
        if(remain < 0) {
            cout << 0 << endl;
        } else {
            cout << int(remain) << endl;
        }
    }
    return 0;
}