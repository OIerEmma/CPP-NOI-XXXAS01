//
// Created by Emma on 2024/12/8.
//
#include<iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if(a > b && a > c) {
        if(b + c > a) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    } else if(b > a && b > c) {
        if(a + c > b) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    } else {
        if(a + b > c) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}