//
// Created by Emma on 2024/11/30.
//
#include<iostream>
using namespace std;

int main() {
    int a, b, c, temp;
    cin >> a >> b >> c;
    if(a < b) {
        temp = a;
        a = b;
        b = temp;
    }
    if(a < c) {
        temp = a;
        a = c;
        c = temp;
    }
    if(b < c) {
        temp = b;
        b = c;
        c = temp;
    }
    cout << a << " " << b << " " << c << endl;
    return 0;
}