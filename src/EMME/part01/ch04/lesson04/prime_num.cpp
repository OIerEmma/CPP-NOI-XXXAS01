//
// Created by Emma on 2025/1/4.
//
#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++) {
        int x = 2;
        while (x <= floor(sqrt(i)) && i % x != 0) {
            x++;
        }
        if (x > floor(sqrt(i))) {
            cout << i << endl;
        }
    }
    return 0;
}