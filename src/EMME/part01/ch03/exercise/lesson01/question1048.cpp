//
// Created by Emma on 2024/12/1.
//
#include<iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if(a < 60 && b < 60) {
        cout << 0 << endl;
    } else if(a > 60 && b > 60) {
        cout << 0 << endl;
    } else {
       cout << 1 << endl;
    }
    return 0;
}