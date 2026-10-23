//
// Created by Emme.Kwok on 2026/10/22.
//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// const int N = 100005;
// int n, a[N];
const int SN = 25;
int n, k, a[SN], path[SN];
bool used[SN];

// 1.全排列
void permute(int step) {
    if (step > n) {
        for (int i = 1; i <= n; i++) cout << path[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (used[i]) continue;
        used[i] = true;
        path[step] = i;
        permute(step + 1);
        used[i] = false;
    }
}

// 2.组合
int ans = 0;
bool isprime(long long x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}
void choose(int start, int chosen, long long sum) {
    if (chosen == k) {
        if (isprime(sum)) ans++;
        return;
    }
    for (int i = start; i <= n; i++)
        choose(i + 1, chosen + 1, sum + a[i]);
}

// 3.查询子集
void subset(int step, long long sum) {
    if (step > n) {
        if (isprime(sum)) ans++;
        return;
    }
    subset(step + 1, sum + a[step]);
    subset(step + 1, sum);
}

vector<int> cur;
vector<vector<int>> allsub;
void subset2(int step, long long sum) {
    if (step > n) {
        allsub.push_back(cur);
        return;
    }
    cur.push_back(a[step]);
    subset2(step + 1, sum + a[step]);
    cur.pop_back();
    subset2(step + 1, sum);
}

bool colUsed[SN], diag1[2 * SN], diag2[2 * SN];
int queen = 0;
void placeQueen(int row) {
    if (row > n) { queen++; return; }
    for (int c = 1; c <= n; c++) {
        if (colUsed[c] || diag1[row + c] || diag2[row - c + n]) continue;
        colUsed[c] = diag1[row + c] = diag2[row - c + n] = true;
        placeQueen(row + 1);
        colUsed[c] = diag1[row + c] = diag2[row - c + n] = false;
    }
}

int main() {
    freopen("xxx.in", "r", stdin);
    freopen("xxx.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    // 解题
    return 0;
}