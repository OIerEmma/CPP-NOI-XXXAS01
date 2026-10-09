//
// Created by Geek.Kwok on 2026/10/9.
//
#include <bits/stdc++.h>
using namespace std;

// check if the network address is valid
// 1. 必须形如 a.b.c.d:e 的格式，其中 a,b,c,d,e 均为非负整数
// 2. 0 ≤ a,b,c,d ≤ 255,0 ≤ e ≤ 65535
// 3. a,b,c,d,e 均不能含有多余的前导 0
bool check(string address) {
    // a
    int pre = 0, pos = address.find('.', pre);
    if (pos == string::npos) return false;
    string a = address.substr(pre, pos - pre);
    // b
    pre = pos + 1, pos = address.find('.', pre);
    if (pos == string::npos) return false;
    string b = address.substr(pre, pos - pre);
    // c
    pre = pos + 1, pos = address.find('.', pre);
    if (pos == string::npos) return false;
    string c = address.substr(pre, pos - pre);
    // d
    pre = pos + 1, pos = address.find(':', pre);
    if (pos == string::npos) return false;
    string d = address.substr(pre, pos - pre);
}

int main() {
    freopen("g_network.in", "r", stdin);
    freopen("g_network.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // 下面开始写本题

    return 0;
}