//
// Created by Geek.Kwok on 2026/3/17.
//
#include <bits/stdc++.h>
using namespace std;

#define N 20
#define ll long long
int n, cnt;
int a[N + 1];
ll vis[N + 1];

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

/**
 *
 * @param step 第几个数
 * @param groups 组数
 */
void dfs(int step, int groups) {
    if (step == n + 1) {
        if (groups < cnt) {
            cnt = groups;
        }
        return;
    }

    // 对于当前的组进行遍历
    for (int i = 1; i <= groups; i++) {
        // 如果与组内所有的数互质 则扔进当前组并继续搜索下一个数
        // 这里比较巧妙的是利用 vis[i] 存储组内所有质数的乘积
        if (gcd(vis[i], a[step]) == 1) {
            vis[i] *= a[step];
            dfs(step + 1, groups);
            vis[i] /= a[step];
        }
    }

    // 当前的数作为一个新组的处理
    vis[groups + 1] *= a[step]; // 将这个数放进下一组
    dfs(step + 1, groups + 1); // 增加一组并继续搜索下一个数
    vis[groups + 1] /= a[step]; // 回溯
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        vis[i] = 1;
    }
    cnt = n + 1;
    dfs(1, 1);
    cout << cnt << endl;
    return 0;
}