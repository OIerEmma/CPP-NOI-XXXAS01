//
// Created by Emma on 2025/7/8.
//
#include<iostream>
using namespace std;

string str[210];

int main() {
    string line;
    getline(cin, line);
    line += " ";
    string s, rep;
    cin >> s >> rep;
    int cnt = 0, last = 0;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == ' ') {
            str[cnt++] = line.substr(last, i - last);
            last = i + 1;
        }
    }
    for (int i = 0; i < cnt; i++) {
        if (str[i] == s) {
            str[i] = rep;
            break;
        }
    }
    for (int i = 0; i < cnt; i++) {
        cout << str[i] << " ";
    }
    return 0;
}