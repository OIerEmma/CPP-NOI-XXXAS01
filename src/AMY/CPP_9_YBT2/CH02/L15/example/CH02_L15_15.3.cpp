//
// Created by Amy on 2026/6/11.
//
#include<iostream>
using namespace std;

int main() {
    int a, b, c, maxx;
    cin >> a >> b >> c;
    maxx = a;
    if(b > maxx) maxx = b;
    if(c > maxx) maxx = c;
    cout << maxx;
    return 0;
}