//
// Created by Geek.Kwok on 2026/10/26.
//
#include <bits/stdc++.h>
using namespace std;

struct Stu {
    int id, chinese, total;
};

bool cmp(const Stu &a, const Stu &b) {
    if (a.total != b.total) return a.total > b.total; // 第一关键字：总分降序
    if (a.chinese != b.chinese) return a.chinese > b.chinese; // 第二关键字：语文降序
    return a.id < b.id; // 第三关键字：学号升序
}

void sortDemo(Stu s[], int n) {
    sort(s + 1, s + n + 1, cmp);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    return 0;
}