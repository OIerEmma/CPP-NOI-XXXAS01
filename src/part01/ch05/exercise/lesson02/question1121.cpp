//
// Created by Emma on 2025/1/22.
//
#include<iostream>
#include<iomanip>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int s = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if (i == 1 || i == m || j == 1 || j == n) {
                s += x;
            }
        }
    }
    cout << s << endl;
    return 0;
}
