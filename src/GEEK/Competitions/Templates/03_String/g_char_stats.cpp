//
// Created by Geek.Kwok on 2026/10/26.
//
#include <bits/stdc++.h>
using namespace std;

string maxNumber(const string& s) {
  int cnt[10] = {0};
  for (int i = 0; i < s.length(); i++)
    if (isdigit(s[i])) cnt[s[i] - '0']++;
  string res;
  for (int d = 9; d >= 0; d--)
    if (cnt[d]) res += string(cnt[d], char(d + '0'));
  return res;
}

// N08T1
string checkISBN(string s) {
  int sum = 0, k = 0;
  for (int i = 0; i < 12; i++)
    if (s[i] != '-') { k++; sum += (s[i] - '0') * k; }
  int r = sum % 11;
  char c = (r == 10) ? 'X' : char('0' + r);
  if (c == s[12]) return "Right";
  s[12] = c;
  return s;
}

int main() {
  string s;
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cin >> s;
  cout << maxNumber(s) << endl;
  return 0;
}