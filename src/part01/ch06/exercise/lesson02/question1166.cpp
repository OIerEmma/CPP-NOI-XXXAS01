//
// Created by Emma on 2025/3/9.
//
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

// 定义：f函数，输入x和n，返回的是 f（n, x）函数的结果
double f(double x, double n) {
    if (n == 1) {
        return sqrt(1 + x);
    }
    return sqrt(n + f(x, n - 1));
}

int main() {
    double n, x;
    cin >> x >> n;
    cout << setprecision(2) << fixed << f(x, n) << endl;
    return 0;
}
