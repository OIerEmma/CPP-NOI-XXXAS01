//
// Created by Emma on 2025/6/30.
//
#include<iostream>
using namespace std;

string s[100];
bool isa(string str) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'a') {
            return true;
        }
    }
    return false;
}

int main() {
    string line;
    getline(cin, line);
    line.erase(line.size() - 1, 1);
    line = line + " ";
    int cnt = 0, last = 0;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == ' ') {
            s[cnt++] = line.substr(last, i - last);
            while (line[++i] == ' ');
            last = i;
        }
    }
    string ans = "NO";
    for (int i = 0; i < cnt; i++) {
        if (isa(s[i]) && ans.size() < s[i].size()) {
            ans = s[i];
        }
    }
    cout << ans << endl;
    return 0;
}