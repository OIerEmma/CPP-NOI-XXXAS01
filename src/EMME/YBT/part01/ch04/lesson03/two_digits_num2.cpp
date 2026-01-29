//
// Created by Emma on 2025/1/2.
//
#include<iostream>
using namespace std;

int main() {
    int a = 1, n, t = 0;
    cin >> n;
    do {
        t++;
        a = (a * 92) % 100;
    } while(t != n);
    cout << a << endl;
    return 0;
}