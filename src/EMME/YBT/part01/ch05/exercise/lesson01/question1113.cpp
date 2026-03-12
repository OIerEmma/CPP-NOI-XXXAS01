//
// Created by Emma on 2025/1/19.
//
#include<iostream>
using namespace std;

int main() {
    int a[105];
    int n;
    cin >> n;
    int max = 0, sum = 0, k = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (max < a[i]) {
            max = a[i];
        }
        sum += a[i];
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == max) {
            k++;
        }
    }
    cout << sum - k * max << endl;
    return 0;
}