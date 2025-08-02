//
// Created by Emma on 2025/7/10.
//
#include<iostream>
using namespace std;

string s[110];

string bl(string s) {
    if (s[0] >= 'a' && s[0] <= 'z') {
        s[0] -= 32;
    }
    return s;
}

int main() {
    string line;
    while(getline(cin, line)) {
        line += " ";
        int last = 0, cnt = 0;
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == ' ' || line[i] == '\n' || line[i] == '\r' || line[i] == '\t') {
                s[cnt++] = line.substr(last, i - last);
                last = i + 1;
            }
        }
        for (int i = 0; i < cnt; i++) {
            s[i] = bl(s[i]);
        }
        for (int i = 0; i < cnt; i++) {
            cout << s[i] << " ";
        }
        cout << endl;
    }
    return 0;
}