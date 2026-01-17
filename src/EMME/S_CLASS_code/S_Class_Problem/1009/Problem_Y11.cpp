//
// Created by Emma on 2025/7/30.
//
#include<iostream>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    for (int t = 1; t <= n; t++) {
        cin >> x;
        int space = x - 1, xing = x;
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= space; j++) {
                cout << " ";
            }
            for (int j = 1; j <= xing; j++) {
                cout << "*";
            }
            cout << endl;
            space--;
            xing += 2;
        }
    }
    return 0;
}
