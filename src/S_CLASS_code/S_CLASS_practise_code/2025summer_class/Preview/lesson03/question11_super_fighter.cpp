//
// Created by Emma on 2025/7/12.
//
#include<iostream>
using namespace std;

int cnt[5010];

int main() {
    int n;
    cin >> n;
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        cnt[x]++;
    }
    int ans = 0;
    for (int i = 1; i <= 5000; i++) {
        int minn = 1e9;
        for (int j = i; j <= 5000; j++) {
            minn = min(minn, cnt[j]);
            ans = max(ans, minn * (j - i + 1));
        }
    }
    cout << ans << endl;
    return 0;
}

/*
17
3 3 4 4 5 5 6 7 8 9 9 9 9 9 9 9 9
*/