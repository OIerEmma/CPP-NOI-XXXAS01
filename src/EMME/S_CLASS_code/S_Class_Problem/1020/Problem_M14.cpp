//
// Created by Emma on 2025/8/11.
//
#include<iostream>
#include<algorithm>
using namespace std;

int a[110];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int t;
    cin >> t;
    sort(a + 1, a + n + 1, greater<int>());
    for (int i = 1; i <= n; i++) {
        if (a[i] == t) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}