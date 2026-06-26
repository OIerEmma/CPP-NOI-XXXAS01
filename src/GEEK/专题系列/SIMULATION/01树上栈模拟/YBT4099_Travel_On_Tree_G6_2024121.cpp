//
// Created by Geek.Kwok on 6/22/26.
//
#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e12;

int main() {
    int n; long long s; string c;
    stack<char> st;
    cin >> n >> s >> c;
    for (int i = 0; i < n; i++) {
        if (c[i] == 'U') {
            if (s == 1L) continue; // 根，无父亲，不动
            if (!st.empty()) { st.pop(); continue; } // 抵消最近一次超界下潜
            s >>= 1; // 真正上行 s -> s/2
        } else if (c[i] == 'L') {
            if ((s << 1) > INF) { st.push('L'); continue; } // 会越界，用栈模拟
            s = s << 1; // 真正下行 s -> 2s
        } else { // R
            if ((s << 1 | 1) > INF) { st.push('R'); continue; } // 会越界，用栈模拟
            s = s << 1 | 1; // 真正下行 s -> 2s + 1
        }
    }
    cout << s << endl;
    return 0;
}