//
// Created by Emma on 2025/3/14.
//
#include<iostream>
#include<cmath>
using namespace std;

// 1.定义：输入一个数a，分解为n个因数，且因数最小值为min，输出分解的种数
int factors(int a, int n, int min) {
    // 2.递归基
    if (a < pow(min, n)) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    // 3.实现已定义的函数
    int cnt = 0;
    for (int i = min; i * i <=  a; i ++) {
        if (a % i == 0) {
            cnt += factors(a / i, n - 1, i);
        }
    }
    return cnt;
}

int main() {
    int n, a, cnt;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a;
        cnt = 0;
        // 2^m <= a <=> m <= log(a) <=> m <= ceil(log(a))
        for (int m = 1; pow(2, m) <= a; m ++) {
            cnt += factors(a, m, 2);
        }
        cout << cnt << endl;
    }
    return 0;
}