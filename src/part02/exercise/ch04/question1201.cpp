//
// Created by Emma on 2025/3/23.
//
#include<iostream>
using namespace std;

int fab(int a) {
    // 递归基 base case
    if (a == 1 || a == 2) {
        return 1;
    }
    return fab(a - 1) + fab(a - 2);
}

int main() {
    int num;
    cin >> num;
    cout << fab(num - 1) << endl;
    return 0;
}