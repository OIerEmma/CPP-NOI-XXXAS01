//
// Created by Emma on 2025/2/8.
//
#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    int n, num, maxValue = -1, minValue = 1001;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        maxValue = max(num, maxValue);
        minValue = min(num, minValue);
    }
    cout << maxValue - minValue << endl;
    return 0;
}
