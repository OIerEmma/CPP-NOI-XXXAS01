//
// Created by Geek.Kwok on 2026/10/26.
//
#include <bits/stdc++.h>
using namespace std;

// sort + unique 版本
int uniqueArr(int a[], int n) {
  sort(a + 1, a + n + 1);
  return (int)(unique(a + 1, a + n + 1) - (a + 1));
}

// vector 版本
void uniqueVec(vector<int>& v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}

// set 版本：自动去重、自动排序
int missingCards(const vector<string>& cards) {
  set<string> st(cards.begin(), cards.end());
  return 52 - st.size();
}


int main() {

  return 0;
}