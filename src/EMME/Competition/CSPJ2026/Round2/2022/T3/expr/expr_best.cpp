//
// Created by Geek.Kwok on 2026/10/3.
//
#include<bits/stdc++.h>
using namespace std;

struct Val {
    int v, cAnd, cOr;
};
stack<Val> vals;
stack<char> ops;

int prio(char c) {
    return c == '&' ? 2 : c == '|' ? 1 : 0;
}

void apply() {
    char c = ops.top(); ops.pop();
    Val b = vals.top(); vals.pop();
    Val a = vals.top(), ans; vals.pop();
    if (c == '&') {
        if (a.v == 0) ans = {0, a.cAnd + 1, a.cOr};
        else ans = {b.v, a.cAnd + b.cAnd, a.cOr + b.cOr};
    } else {
        if (a.v == 1) ans = {1, a.cAnd, a.cOr + 1};
        else ans = {b.v, a.cAnd + b.cAnd, a.cOr + b.cOr};
    }
    vals.push(ans);
}

int main() {
    string s;
    cin >> s;
    for (char c : s) {
        if (c == '0' || c == '1') vals.push({c - '0', 0, 0});
        else if (c == '(') ops.push(c);
        else if (c == ')') {
            while (ops.top() != '(') apply();
            ops.pop();
        } else {
            while (!ops.empty() && prio(ops.top()) >= prio(c)) apply();
            ops.push(c);
        }
    }
    while (!ops.empty()) apply();
    cout << vals.top().v << endl << vals.top().cAnd << " " << vals.top().cOr << endl;
    return 0;
}