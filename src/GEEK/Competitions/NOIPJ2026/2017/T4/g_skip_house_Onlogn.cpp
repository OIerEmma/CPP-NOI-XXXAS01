//
// Created by Geek.Kwok on 2026/10/9.
//
#include <bits/stdc++.h>
using namespace std;

const long long NEG_INF = LLONG_MIN / 4;
const int MAXN = 500005;
int n, d;
long long k, x[MAXN], s[MAXN], f[MAXN];
int q[MAXN];

bool check(int g) {
  long long lo = max(1, d-g), hi = d+g;
  x[0] = 0; f[0] = 0;
  int head = 0, tail = 0, j = 0;
  for (int i = 1; i <= n; i++) {
    // push tail
    while (j < i && x[i] - x[j] >= lo) {
      if (f[j] != NEG_INF) {
        while (head < tail && f[q[tail-1]] <= f[j]) tail--;
        q[tail++] = j;
      }
      j++;
    }
    // pop head
    while (head < tail && x[i] - x[q[head]] > hi) head++;
    // compute f[i]
    if (head < tail) f[i] = f[q[head]] + s[i];
    else f[i] = NEG_INF;
    // check
    if (f[i] >= k) return true;
  }
  return false;
}

int main() {
  scanf("%d %d %lld", &n, &d, &k);
  long long positiveSum = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%lld %lld", &x[i], &s[i]);
    if (s[i] > 0) positiveSum += s[i];
  }
  if (positiveSum < k) { printf("-1\n"); return 0;}
  int lo = 0, hi = (int)x[n];
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (check(mid)) hi = mid;
    else lo = mid + 1;
  }
  printf("%d\n", lo);
  return 0;
}