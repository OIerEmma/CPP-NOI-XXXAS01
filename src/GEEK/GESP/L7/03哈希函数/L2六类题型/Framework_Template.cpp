//
// Created by Geek.Kwok on 2026/9/8.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  unordered_map<long long, long long> mp; // 位置①：表里存什么
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    // 位置②：查什么（当前值？配对值？前缀值？）
    // 位置③：答案怎么加
    // 位置④：什么时候插入（先查再插，还是先全部插完再查）
  }
  cout << ans << endl;
  return 0;
}