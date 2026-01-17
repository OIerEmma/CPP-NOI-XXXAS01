//
// Created by Emma on 2024/12/8.
//
#include<iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    if(a % 4 == 0) {
        if(a % 100 != 0) {
            cout << "Y" << endl;
        } else {
            if(a % 400 == 0) {
                cout << "Y" << endl;
            } else {
                cout << "N" << endl;
            }
        }
    } else {
        cout << "N" << endl;
    }
}