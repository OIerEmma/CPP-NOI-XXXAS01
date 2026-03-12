//
// Created by Amy on 2026/3/9.
//
#include<iostream>
using namespace std;

int main() {
    int T, P;
    cin >>T;
    for(int i = 0;i < T;i++) {
        cin >> P;
        if (P <= 10)
            cout << "R" << endl;
        else if (P <= 20)
            cout << "L" << endl;
        else if (P > 20)
            cout << P << endl;
    }
    return 0;
}