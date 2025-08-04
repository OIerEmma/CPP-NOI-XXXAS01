//
// Created by Emma on 2025/8/4.
//
#include<iostream>
using namespace std;

int main() {
    int num;
    for (int i = 1; i <= 20; i++) {
        cin >> num;
        if (num == 10) {
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}