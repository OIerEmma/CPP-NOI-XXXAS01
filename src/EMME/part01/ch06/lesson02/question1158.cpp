//
// Created by Emma on 2025/3/8.
//
#include<iostream>
using namespace std;

int addall(int n) {
    if (n == 1) {
        // 终止条件
        return 1;
    }
    return n + addall(n - 1); // 递归调用
}

int main() {
    int n;
    cin >> n;
    printf("%d\n", addall(n));
    return 0;
}
