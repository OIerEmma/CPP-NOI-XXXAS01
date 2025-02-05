//
// Created by Emma on 2025/1/18.
//
#include<iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    if (a > 0) {
        cout << a << ">0" << endl;
    } else if (a < 0) {
        cout << a << "<0" << endl;
    } else {
        cout << a << "=0" << endl;
    }
    return 0;
}
