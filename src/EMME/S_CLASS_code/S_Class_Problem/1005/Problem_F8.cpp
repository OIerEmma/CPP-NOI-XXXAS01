//
// Created by Emma on 2025/7/8.
//
#include<iostream>
using namespace std;

int b[30010];

int main() {
    int n;
    cin >> n;
    int num, ans;
    for (int i = 0; i < n; i++) {
        cin >> num;
        b[num]++;
    }
    for (int i = 0; i < n; i++) {
        ans = max(ans, b[i]);
    }
    for (int i = 0; i < 30010; i++) {
        if (b[i] == ans) {
            cout << i << " " << b[i] << endl;
        }
    }
    return 0;
}