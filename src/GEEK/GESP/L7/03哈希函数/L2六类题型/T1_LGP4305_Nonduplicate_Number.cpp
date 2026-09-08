//
// Created by Geek.Kwok on 2026/9/8.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> T;
  while (T--) {
    int n; cin >> n;
    unordered_set<int> seen;
    bool firstOut = true;
    for (int i = 0; i < n; i++) {
      int x; cin >> x;
      if (!seen.count(x)) {
        seen.insert(x);
        if (!firstOut) cout << " ";
        cout << x;
        firstOut = false;
      }
    }
    cout << "\n";
  }
  return 0;
}