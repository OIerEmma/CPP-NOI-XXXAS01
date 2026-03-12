//
// Created by Geek.Kwok on 2026/2/8.
//
#include<iostream>
using namespace std;

string num[25];

bool cmp(string s1, string s2) {
    for (int i = 0; i < min(s1.size(), s2.size()); i++) {
        if (s1[i] > s2[i]) {
            return true;
        }
        if (s1[i] < s2[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n - i - 1; j++) {
            if (!cmp(num[j], num[j + 1])) {
                swap(num[j], num[j + 1]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << num[i];
    }
    return 0;
}