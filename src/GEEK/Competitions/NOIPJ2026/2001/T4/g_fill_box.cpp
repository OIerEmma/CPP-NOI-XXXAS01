//
// Created by Geek.Kwok on 2026/10/30.
//
#include <bits/stdc++.h>
using namespace std;

int V, n, b[35];
bool dp[20005];

int main() {
  cin >> V >> n;
  for (int i = 1; i <= n; i++) cin >> b[i];
  memset(dp, 0, sizeof dp);
  dp[0] = true;
  for (int i = 1; i <= n; i++)
    for (int j = V; j >= b[i]; j--)
      if (dp[j - b[i]]) dp[j] = true;
  for (int v = V; v >= 0; v--)
    if (dp[v]) {
      cout << V - v << endl;
      break;
    }
  return 0;
}