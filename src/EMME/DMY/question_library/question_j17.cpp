//
// Created by Emme.Kwok on 2026/1/10.
//
#include<iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    cout << a % 10 + a / 10 % 10 + a / 100;
    return 0;
}