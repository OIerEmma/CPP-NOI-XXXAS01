//
// Created by Emme.Kwok on 2026/10/11.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool check(string s) {
        stack<char> op;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')') {
                if (op.empty() || op.top() != '(') return false;
                op.pop();
            } else if (s[i] == ']') {
                if (op.empty() || op.top() != '[') return false;
                op.pop();
            }  else if (s[i] == '}') {
                if (op.empty() || op.top() != '{') return false;
                op.pop();
            } else op.push(s[i]);
        }
        if (!op.empty()) return false;
        return true;
    }
public:
    bool isValid(string s) {
        return check(s);
    }
};