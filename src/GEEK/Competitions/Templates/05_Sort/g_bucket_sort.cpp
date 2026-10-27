//
// Created by Geek.Kwok on 2026/10/26.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 605;
int n, w, cnt[N];

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr), cout.tie(nullptr);
  scanf("%d %d", &n, &w);
  for (int p = 1, s; p <= n; p++) {
    scanf("%d", &s);
    cnt[s]++;
    int k = max(1, p * w / 100);
    int ans = 0;
    for (int i = 600; i >= 0; i--) {
      ans += cnt[i];
      if (ans >= k) { printf("%d ", i); break; }
    }
  }
  printf("\n");
  return 0;
}