//
// Created by Geek.Kwok on 6/22/26.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> c(N), pa(N), cnt(N);
long long ans[N];

int main() {
    int n;
    cin >> n;
    // 统计每个节点的孩子数（判叶子）
    for (int i = 2; i <= n; i++) {
        cin >> pa[i];
        cnt[pa[i]]++;
    }
    for (int i = 1; i <= n; i++) cin >> c[i];
    // 迭代递推：防止爆栈
    for (int i = n; i >= 1; i--) {
      if (cnt[i] == 0) ans[i] = c[i]; // 叶子节点 ans 初值即 c[i]
      ans[i] = min(ans[i], static_cast<long long>(c[i])); // 与“染自己”比较取较小
      ans[pa[i]] += ans[i]; // 把自己的结果累加给父亲
    }
    // 取答案
    cout << ans[1] << endl;
    return 0;
}