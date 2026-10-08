//
// Created by Geek.Kwok on 2026/10/3.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    string s;
    getline(cin, s);
    stack<long long> st;
    long long num = 0;
    bool hasNum = false;
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
            hasNum = true;
        } else if (c == '.') {
            if (hasNum) {
                st.push(num);
                num = 0;
                hasNum = false;
            }
        } else if (c == '@') {
            break;
        } else {
            if (hasNum) {
                st.push(num);
                num = 0;
                hasNum = false;
            }
            long long b = st.top(); st.pop();
            long long a = st.top(); st.pop();
            if (c == '+') st.push(a + b);
            else if (c == '-') st.push(a - b);
            else if (c == '*') st.push(a * b);
            else if (c == '/') st.push(a / b);
        }
    }
    cout << st.top() << '\n';
    return 0;
}