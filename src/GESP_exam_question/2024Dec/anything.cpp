//
// Created by Emma on 2025/2/6.
//
#include<iostream>
using namespace std;

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    int res = 0;
    for (int i = 0; i < 5; i++) {
        res *= a[i];
    }
    cout << res;
}