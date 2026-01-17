//
// Created by Emme.Kwok on 2025/9/19.
//
#include<iostream>
#include<cmath>
using namespace std;

int memo[1000010];

int f(int x) {
    if (x == 0) {
        return 1;
    }
    if (memo[x]) {
        return memo[x];
    }
    memo[x] = (f(int(x - sqrt(x))) + f(int(log(x))) + f(int(x * sin(x) * sin(x)))) % 1000000;
    return memo[x];
}

int main() {
    int n;
    while (cin >> n) {
        if (n == -1) {
            break;
        }
        cout << f(n) % 1000000 << endl;
    }
    return 0;
}