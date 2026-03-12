//
// Created by Emme.Kwok on 2026/1/24.
//
#include<iostream>
using namespace std;

const int maxn = 95;
int moon[maxn];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> moon[i];
    }
    if (n == 1) {
        if (moon[1] == 0) {
            cout << "UP" << endl;
        } else if (moon[1] == 15) {
            cout << "DOWN" << endl;
        } else {
            cout << "-1" << endl;
        }
    } else {
        if (moon[n] == 0 || (moon[n] >= 1 && moon[n] <= 14 && moon[n] > moon[n - 1])) {
            cout << "UP" << endl;
        } else if (moon[n] == 15 || (moon[n] >= 1 && moon[n] <= 14 && moon[n] < moon[n - 1])) {
            cout << "DOWN" << endl;
        }
    }
    return 0;
}