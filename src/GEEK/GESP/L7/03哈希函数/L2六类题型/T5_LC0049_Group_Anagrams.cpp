//
// Created by Geek.Kwok on 2026/9/8.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string sortAnagram(string& str) {
    string key = str;
    sort(key.begin(), key.end());
    return key;
  }
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (auto& str : strs) mp[sortAnagram(str)].push_back(str);
    vector<vector<string>> res;
    for (const auto& it : mp) res.push_back(it.second);
    return res;
  }
};

int main() {
  return 0;
}