//
// Created by Emme.Kwok on 2026/6/24.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int m, n, k;
    cin >> m >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> ques[m + 1];
    for (int i = 0; i < n; i++)
        cin >> b[i], ques[a[i]].push_back(b[i]);
    for (int i = 1; i <= m; i++)
        sort(ques[i].begin(), ques[i].end(), greater<int>());
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        int cnt = 0, j = 0;
        while (cnt < k && j < ques[i].size()) {
            cnt += ques[i][j];
            ans++, j++;
        }
        if (cnt < k) cout << -1 << endl, exit(0);
    }
    cout << ans << endl;
    return 0;
}
