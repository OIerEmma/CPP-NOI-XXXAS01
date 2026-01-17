//
// Created by Emme.Kwok on 2025/12/20.
//
#include<iostream>
using namespace std;

bool a[1010];

int main() {
    int n, m, x;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x;
        a[x] = true;
    }
    bool f = false;
    for (int i = 0; i < n; i++) {
        if (!a[i]) {
            cout << i << " ";
            f = true;
        }
    }
    if (!f) {
        cout << n << endl;
    }
    return 0;
}