//
// Created by Emma on 2025/4/4.
//
#include<iostream>
using namespace std;

void two_power(int m, int n) {
    if (m == 0) { // 递归基
        return;
    }
    int temp = m % 2;
    m /= 2;
    two_power(m, n + 1); // 开始时的递归函数调用
    if (m != 0 && temp != 0) { // 如果都不是0输出+
        printf("+");
    }
    if (temp == 1) {
        if (n == 0) { // n是0时为2(0)
            printf("2(0)");
        } else if (n == 1) { // n是1时为2
            printf("2");
        } else if (n == 2) { // n是2时为2(2)
            printf("2(2)");
        } else { // 其他情况进行递归函数调用
            printf("2(");
            two_power(n, 0);
            printf(")");
        }
    }
}

int main() {
    int num;
    scanf("%d", &num);
    two_power(num, 0);
    return 0;
}
