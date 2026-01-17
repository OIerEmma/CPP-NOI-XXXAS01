//
// Created by Emma on 2025/8/5.
//
#include<iostream>
using namespace std;

int main() {
    int n, start = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << start + j << " ";
        }
        start++;
        cout << endl;
    }
    return 0;
}