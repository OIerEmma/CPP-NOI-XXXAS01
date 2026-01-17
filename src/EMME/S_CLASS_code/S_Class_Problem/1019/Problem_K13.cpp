//
// Created by Emma on 2025/8/5.
//
#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int space = n - 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= space; j++) {
            cout << " ";
        }
        for (int j = 1; j < i; j++) {
            cout << j;
        }
        cout << i;
        for (int j = i - 1; j >= 1; j--) {
            cout << j;
        }
        cout << endl;
        space--;
    }
    return 0;
}