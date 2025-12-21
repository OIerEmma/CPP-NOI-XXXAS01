//
// Created by Emma on 2025/8/20.
//
#include<iostream>
using namespace std;

int stk[1010], a[1010];

int main() {
    int top = 0, n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    bool flag = false;
    for (int i = 1, cur = 1; i <= n; i++) {
        while (cur <= a[i]) {
            stk[++top] = cur;
            cur++;
        }
        if (stk[top] == a[i]) {
            --top;
        } else {
            cout << "NO" << endl;
            flag = true;
            break;
        }
    }
    if (!flag) {
        cout << "YES" << endl;
    }
    return 0;
}