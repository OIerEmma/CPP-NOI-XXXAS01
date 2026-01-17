//
// Created by Emma on 2025/8/11.
//
#include<iostream>
#include<algorithm>
using namespace std;

int a[110], r[110];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        r[i] = a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (r[i] == a[j]) {
                cout << j - 1 << " ";
                break;
            }
        }
    }
    return 0;
}
