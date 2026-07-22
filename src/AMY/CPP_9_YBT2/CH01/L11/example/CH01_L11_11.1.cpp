//
// Created by Amy on 2026/5/4.
//
#include<iostream>
using namespace std;

int main() {
    int x,y,c,r;
    cin >> x >> y;
    r = (y-2*x)/2;
    c = x - r;
    cout << c << ' ' << r;
    return 0;
}