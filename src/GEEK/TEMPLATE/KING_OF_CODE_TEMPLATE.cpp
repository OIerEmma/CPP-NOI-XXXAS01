#include <bits/stdc++.h>
using namespace std;

// 全局常量定义
const int N = 1e5 + 5;  // 根据题目数据范围调整
const int MOD = 1e9 + 7;  // 题目要求取模

// 全局变量定义
vector<int> a(N, 0);  // int a[N];
vector<long long> dp(N, 0);  // long long DP[N];
vector<int> children[N];

int main() {
    // IO优化：加快输入输出速度
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 读入数据
    int n, ans = 0;
    cin >> n;

    // 核心算法

    // 输出结果
    cout << ans << endl;

    return 0;
}