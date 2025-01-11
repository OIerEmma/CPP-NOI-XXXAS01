//
// Created by Emma on 2025/1/2.
//
#include<iostream>
using namespace std;

int main() {
    // int x = 7;
    // do {
    //     x += 7;
    // } while (x % 2 != 1 || x % 3 != 1 || x % 4 != 1 || x % 5 != 1 || x % 6 != 1);
    // cout << x << endl;
    int x = 0;
    bool yes;
    do {
        yes = true;
        x += 7;
        if (x % 2 != 1) {
            yes = false;
        } else if (x % 3 != 1) {
            yes = false;
        } else if (x % 4 != 1) {
            yes = false;
        } else if (x % 5 != 1) {
            yes = false;
        } else if (x % 6 != 1) {
            yes = false;
        }
    } while (yes == false);
    cout << x << endl;
    return 0;
}
