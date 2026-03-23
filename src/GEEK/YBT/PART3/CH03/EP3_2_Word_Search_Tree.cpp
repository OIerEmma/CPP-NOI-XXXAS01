//
// Created by Geek.Kwok on 2026/3/22.
//
#include <bits/stdc++.h>
using namespace std;

int i, j, n, t, k;
string a[8001];
string s;

int main() {
    // freopen("word.in", "r", stdin);
    // freopen("word.out", "w", stdout);
    while (cin>>a[++n]);
    n--;
    sort(a + 1, a + n + 1);
    t = a[1].length(); // 先累加第1个单词的长度
    for (i = 2; i <= n; i++) { // 依次计算每个单词对前一个单词的差
        j = 0;
        while (a[i][j] == a[i-1][j] && j < a[i-1].length()) j++; // 求两个单词相同部分的长度
        t += a[i].length() - j; // 累加两个单词的差 a[i].length - j
    }
    cout << t + 1 << endl;
    return 0;
}