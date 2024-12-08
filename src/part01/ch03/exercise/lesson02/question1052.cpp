//
// Created by Emma on 2024/12/8.
//
#include<iostream>
using namespace std;

int main() {
    int g, m;
    char e;
    cin >> g >> e;
    if(e == 'y') {
        m = 5;
    } else {
        m = 0;
    } if(g < 1000) {
        m += 8;
        cout << m << endl;
    } else {
        if((g - 1000) % 500 == 0) {
             m += ((g - 1000) / 500) * 4 + 8;
             cout << m << endl;
        } else {
            m += ((g - 1000) / 500 + 1) * 4 + 8;
            cout << m << endl;
        }
    }
}