//
// Created by Geek.Kwok on 2026/1/10.
//
#include<iostream>
using namespace std;

const int maxn = 25;
int n, k, a[maxn], b[maxn];
long long res[1000010];

void dfs(int step) {
   if (step == n + 1) {
      long long sum = 0;
      for (int i = 1; i <= n; i++) {
         if (b[i]) {
            sum += a[i];
         }
      }
      res[sum % k]++;
      return;
   }
   for (int i = 1; i >= 0; i--) {
      b[step] = i;
      dfs(step + 1);
   }
}

int main() {
   cin >> n >> k;
   for (int i = 1; i <= n; i++) {
      cin >> a[i];
   }
   dfs(1);
   for (int i = 0; i < k; i++) {
      cout << res[i] << endl;
   }
}