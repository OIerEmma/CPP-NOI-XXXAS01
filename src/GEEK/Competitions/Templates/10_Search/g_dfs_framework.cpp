//
// Created by Geek.Kwok on 2026/10/22.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005;
// int n, a[N];

int main() {
    freopen("xxx.in", "r", stdin);
    freopen("xxx.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // cin >> n;
    // for (int i = 1; i <= n; i++) cin >> a[i];
    // ...解题...
    return 0;
}

const int SN = 25;
int n, k, a[SN], path[SN];
bool used[SN];

// 1全排列：第 pos 个位置填哪个数
void permute(int pos) {
    if (pos > n) { // 所有位置都填完了
        for (int i = 1; i <= n; i++) cout << path[i] << " ";
        cout << endl;
        return;
    }
    for (int x = 1; x <= n; x++) {
        if (used[x]) continue;
        used[x] = true; path[pos] = x;  // 做
        permute(pos + 1);               // 递归
        used[x] = false;                // 撤销
    }
}
// permute(1);

// 2组合：从 a[1..n] 中选 k 个（N02T2选数：和为质数的选法有几种）
bool isPrimeInt(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) if (x % i == 0) return false;
    return true;
}
int ansCnt = 0;
void choose(int start, int chosen, int sum) { // 从 start 开始选，已选 chosen 个，和为 sum
    if (chosen == k) {
        if (isPrimeInt(sum)) ansCnt++;
        return;
    }
    for (int i = start; i <= n; i++) // 下一个只能从后面选，保证不重复
        choose(i + 1, chosen + 1, sum + a[i]);
}
// choose(0, 0, 0);

// 3子集：第 i 个数选或不选
void subset(int i, int sum) {
    if (i > n) {
        // 找到一个子集，和为 sum
        return;
    }
    subset(i + 1, sum + a[i]); // 选第 i 个
    subset(i + 1, sum);        // 不选第 i 个
}
// subset(1, 0);
vector<int> cur;
vector<vector<int>> allSubsets;
void subsets(int i, int sum) {
    if (i > n) {
        // 找到一个子集，和为 sum
        allSubsets.push_back(cur); // 记录该子集
        return;
    }
    cur.push_back(a[i]);
    subsets(i + 1, sum + a[i]); // 选第 i 个
    cur.pop_back(); // 回溯，恢复现场
    subsets(i + 1, sum);        // 不选第 i 个
}
// subsets(1, 0);

// 4N皇后：每行放一个，列和两条对角线不能冲突，求方案数
bool colUserd[SN], diag1[SN], diag2[SN];
int queens = 0;
void placeQueens(int row) {
    if (row > n) { queens++; return; }
    for (int c = 1; c <= n; c++) {
        if (colUserd[c] || diag1[row + c] || diag2[row - c + n]) continue;
        colUserd[c] = diag1[row + c] = diag2[row - c + n] = true;
        placeQueens(row + 1);
        colUserd[c] = diag1[row + c] = diag2[row - c + n] = false;
    }
}
// placeQueens(1);