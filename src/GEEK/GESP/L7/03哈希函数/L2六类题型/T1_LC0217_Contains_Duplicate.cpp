//
// Created by Geek.Kwok on 2026/9/8.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  unordered_set<int> seen;
  bool dup = false;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    if (seen.count(x)) dup = true;
    else seen.insert(x);
  }
  if (dup) cout << "Yes\n";
  else cout << "No\n";
  return 0;
}

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    for (auto num: nums) {
      if (seen.count(num)) return true;
      seen.insert(num);
    }
    return false;
  }
};