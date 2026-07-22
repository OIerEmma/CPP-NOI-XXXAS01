//
// Created by Geek.Kwok on 7/22/26.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];

  int ans = 0;
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= n; i++) { dp[i][i] = a[i]; ans = max(ans, dp[i][i]); }

  for (int len = 2; len <= n; len++)
    for (int i = 1; i + len - 1 <= n; i++) {
      int j = i + len - 1;
      for (int k = i; k < j; k++)
        if (dp[i][k] == dp[k+1][j] && dp[i][k]) {
          dp[i][j] = max(dp[i][j], dp[i][k] + 1);
          ans = max(ans, dp[i][j]);
        }
    }

  cout << ans << endl;
  return 0;
}