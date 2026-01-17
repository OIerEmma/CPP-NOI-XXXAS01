//
// Created by Emma on 2025/3/8.
//
#include<iostream>
using namespace std;

int fibonacci(int n) {
    // 基准情况
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    // 递归步骤
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n - 1) << endl;
    return 0;
}
