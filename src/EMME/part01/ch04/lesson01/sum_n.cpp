//
// Created by Emma on 2024/12/19.
//
#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    long long s = 1;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        s *= i;
    }
    cout << s << endl;
    return 0;
}