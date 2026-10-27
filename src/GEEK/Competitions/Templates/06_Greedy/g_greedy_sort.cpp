//
// Created by Geek.Kwok on 2026/10/26.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// N07T2
int minGroups(int a[], int n, int w) {
  sort(a + 1, a + n + 1);
  int i = 1, j = n, groups = 0;
  while (i <= j) {
    if (i < j && a[i] + a[j] <= w) i++;
    j--;
    groups++;
  }
  return groups;
}

// 排队接水：n 人接水时间 t[i]，求平均等待时间最小 -> 时间短的先接
double minAvgWait(int t[], int n) {
  sort(t + 1, t + n + 1);
  ll total = 0, now = 0;
  for (int i = 1; i <= n; i++) {
    total += now;
    now += t[i];
  }
  return (double) total / n;
}

int main() {

  return 0;
}