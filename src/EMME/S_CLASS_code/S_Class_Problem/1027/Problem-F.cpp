//
// Created by Emma on 2024/11/24.
//
#include<iostream>
#include<cstdio>

using namespace std;

int main() {
    int r, h, int_x;
    double a, x;
    cin >> h >> r;
    a = r * r * 3.14 * h;
    x = 20000.0 / a;
    int_x = int(20000 / a);
    if(x > int_x) {
        int_x += 1;
    }
    cout << int_x << endl;
    return 0;
}
