//
// Created by Emma on 2024/11/14.
//
#include<iostream>
using namespace std;

int main() {
    int x = 7, y = 8;
    int z1 = y - (x++);
    int z2 = y - (++x);
    cout << "z1=" << z1 << endl << "z2=" << z2 << endl;
    return 0;
}