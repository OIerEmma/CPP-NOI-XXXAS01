//
// Created by Emma on 2025/4/6.
//
#include<iostream>
using namespace std;

int mutall(int n) {
    if (n == 1) {
        // 终止条件
        return 1;
    }
    return n * mutall(n - 1); // 递归调用
}

int main() {
    int n;
    cin >> n;
    printf("%d\n", mutall(n));
    return 0;
}
