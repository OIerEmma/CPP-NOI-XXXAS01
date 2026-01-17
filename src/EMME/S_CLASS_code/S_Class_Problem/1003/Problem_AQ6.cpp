//
// Created by Emma on 2025/7/5.
//
#include<iostream>
using namespace std;

int a[100];

int main() {
    int n;
    cin >> n;
    int maxx = -1, minn = 32768;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxx = max(maxx, a[i]);
        minn = min(minn, a[i]);
    }
    cout << maxx << " " << minn << endl;
    return 0;
}