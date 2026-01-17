//
// Created by Emma on 2025/7/7.
//
#include<iostream>
using namespace std;

bool one(int n) {
    int zero = 0, one = 0;
    while (n != 0) {
        if (n % 10 == 1) {
            one++;
        } else if (n % 10 == 0) {
            zero++;
        }
        n /= 10;
    }
    return one > zero;
}

int twodata(int num) {
    string s;
    if (num == 1) {
        return 1;
    }
    while (num >= 1) {
        s = to_string(num % 2) + s;
        num /= 2;
    }
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        ans = ans * 10 + (s[i] - 48);
    }
    return ans;
}

int main() {
    int a = 0, b = 0;
    for (int i = 1; i <= 1000; i++) {
        if (one(twodata(i))) {
            a++;
        } else {
            b++;
        }
    }
    cout << a << " " << b << endl;
    return 0;
}