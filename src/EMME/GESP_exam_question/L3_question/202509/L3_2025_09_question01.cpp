//
// Created by Emme.Kwok on 2025/12/21.
//
#include<iostream>
using namespace std;

int a[110], n;

bool allz() {
    for (int i = 1; i <= n; i++) {
        if (a[i] != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    while (!allz()) {
        ans++;
        int maxx = 0, minn = 101, maxi = -1;
        for (int i = 1; i <= n; i++) {
            if (a[i] >= maxx) {
                maxx = a[i];
                maxi = i;
            }
            if (a[i] < minn && a[i] != 0) {
                minn = a[i];
            }
        }
        a[maxi] -= minn;
    }
    cout << ans << endl;
    return 0;
}