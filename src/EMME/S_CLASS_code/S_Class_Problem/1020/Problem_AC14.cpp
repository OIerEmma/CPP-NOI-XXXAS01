//
// Created by Emma on 2025/8/11.
//
#include<iostream>
using namespace std;

int id[110], r[110];

int main() {
    int n, a;
    cin >> n >> a;
    for (int i = 1; i <= n; i++) {
        cin >> id[i];
    }
    int ans = 0, cnt = 1;
    for (int i = 1; i <= n; i++) {
        if (id[i] == a) {
            ans++;
            r[cnt++] = i;
        }
    }
    if (ans == 0) {
        cout << "NOBODY" << endl;
    } else {
        for (int i = 1; i < cnt; i++) {
            cout << r[i] << " ";
        }
        cout << endl << "zongshu:" << ans << endl;
    }
    return 0;
}