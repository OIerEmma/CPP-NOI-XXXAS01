//
// Created by Geek.Kwok on 7/1/26.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, M;
    cin >> T >> M;
    vector<int> w(M), v(M);
    for (int i = 0; i < M; i++) cin >> w[i] >> v[i];
    // 初始化
    vector<int> dp(T + 1, 0);
    // 顺序
    for (int i = 0; i < M; i++)
        for (int j = T; j >= w[i]; j--)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    // 答案
    cout << dp[T] << endl;
  return 0;
}