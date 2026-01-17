//
// Created by Emma on 2025/8/11.
//
#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < 7; i++) {
        n += 2;
        n *= 2;
    }
    cout << n << endl;
    return 0;
}