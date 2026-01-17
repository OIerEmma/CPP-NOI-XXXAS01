//
// Created by Emma on 2025/3/8.
//
#include<iostream>
#include<cmath>
using namespace std;

// 定义：输入为 n 则该函数返回 n 的逆序
long long reverse(long long n) {
    if (n < 10) {
        return n;
    }
    long long a = n % 10; // 3
    long long b = n / 10; // 12
    string s = to_string(b);
    long long len = pow(10, s.length());
    return a * len + reverse(b);
}

string reverse2(string s) {
    if (s.length() <= 1) {
        return s;
    }
    return s[s.length() - 1] + reverse2(s.substr(0, s.length() - 1));
}

int main() {
    string n;
    cin >> n;
    cout << reverse2(n) << endl;
    return 0;
}
