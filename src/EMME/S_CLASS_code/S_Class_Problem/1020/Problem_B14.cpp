//
// Created by Emma on 2025/8/6.
//
#include<iostream>
using namespace std;

int a[50010], b[1000010];

int main() {
    int n, idx = 0, num = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (b[a[i]] == 1) {
            if (idx == 0) {
                idx = i;
                num = a[i];
            }
        } else {
            b[a[i]]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (num == a[i]) {
            cout << i << " " << idx << endl;
            break;
        }
    }
    return 0;
}
