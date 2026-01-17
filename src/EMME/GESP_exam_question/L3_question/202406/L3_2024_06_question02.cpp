//
// Created by Emme.Kwok on 2025/12/21.
//
#include<iostream>
using namespace std;

int a[100010];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, maxx = 0;
        bool flag = false;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            maxx = max(a[i], maxx);
        }
        for (int i = 1; i <= n; i++) {
            if (maxx % a[i] != 0) {
                cout << "No" << endl;
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << "Yes" << endl;
        }
    }
    return 0;
}