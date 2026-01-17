//
// Created by Emma on 2025/8/2.
//
#include<iostream>
using namespace std;

int main() {
    int n, big = 0, mid = 0, sma = 0, num;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        if (num >= 145) {
            big++;
        } else if (num < 135) {
            sma++;
        } else {
            mid++;
        }
    }
    cout << big << " " << mid << " " << sma << endl;
    return 0;
}