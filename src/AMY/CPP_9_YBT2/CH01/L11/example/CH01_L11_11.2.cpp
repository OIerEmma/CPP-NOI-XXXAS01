//
// Created by Amy on 2026/5/4.
//
#include<iostream>
using namespace std;

int main() {
    int n,gw,sw,bw;
    cin >> n;
    gw = n % 10,n /= 10;
    sw = n % 10,n /= 10;
    bw = n % 10,n /= 10;
    cout << gw * 100 + sw * 10 + bw;
    return 0;
}