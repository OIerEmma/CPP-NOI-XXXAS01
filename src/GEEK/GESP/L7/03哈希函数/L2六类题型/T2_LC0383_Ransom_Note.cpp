//
// Created by Geek.Kwok on 2026/9/8.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        for (char c : magazine) m[c]++;
        for (char c : ransomNote) {
            if (m[c] <= 0) return false;
            m[c]--;
        }
        return true;
    }
};