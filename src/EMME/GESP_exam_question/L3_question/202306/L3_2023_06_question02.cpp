//
// Created by Emme.Kwok on 2025/12/20.
//
#include<iostream>
using namespace std;

string s[101];

bool check(string s) {
    if (s.size() < 6 || s.size() > 12) {
        return false;
    }
    bool bi = false, sm = false, num = false, t = false;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c >= 'a' && c <= 'z') {
            sm = true;
        }
        if (c >= 'A' && c <= 'Z') {
            bi = true;
        }
        if (c >= '0' && c <= '9') {
            num = true;
        }
        if (c == '!' || c == '@' || c == '#' || c == '$') {
            t = true;
        }
        if (!(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9'|| c == '!' || c == '@' || c == '#' || c == '$')) {
            return false;
        }
    }
    int ans = sm + bi + num;
    if (ans < 2 || !t) {
        return false;
    }
    return true;
}

int main() {
    string line;
    cin >> line;
    int pos = 0, cnt = 1;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == ',') {
            s[cnt++] = line.substr(pos, i - pos);
            pos = i + 1;
        }
    }
    s[cnt++] = line.substr(pos, line.size() - pos);
    for (int i = 1; i < cnt; i++) {
        if (check(s[i])) {
            cout << s[i] << endl;
        }
    }
    return 0;
}