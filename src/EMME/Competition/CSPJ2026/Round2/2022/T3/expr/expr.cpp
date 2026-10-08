//
// Created by Geek.Kwok on 2026/10/3.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("expr.in", "r", stdin);
    freopen("expr.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    string s;
    cin >> s;
    stack<char> sym;
    stack<int> num;
    int yu = 0, huo = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ')') {
            while (sym.top() != '(') {
                int first = num.top();
                num.pop();
                int second = num.top();
                num.pop();
                char c = sym.top();
                if (first == 0 && c == '&') yu++;
                if (second == 1 && c == '|') huo++;
                int x;
                if (c == '|') x = first | second;
                else x = first & second;
                num.push(x);
            }
        } else if (s[i] == '0' || s[i] == '1') {
            num.push(s[i] - '0');
        } else {
            sym.push(s[i]);
        }
    }
    cout << num.top() << endl << yu << " " << huo << endl;
    return 0;
}