//
// Created by Emma on 2025/7/4.
//
#include<iostream>
using namespace std;

string s[210];

int main() {
    string line;
    int cnt = 0, pos = 0;
    getline(cin, line);
    line = line + " ";
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == ' ' || line[i] == ',') {
            s[cnt++] = line.substr(pos, i - pos);
            while (line[++i] == ' ' || line[i] == ',');
            pos = i;
            i--;
        }
    }
    string maxs = s[0], mins = s[0];
    for (int i = 1; i < cnt; i++) {
        if (s[i].size() > maxs.size()) {
            maxs = s[i];
        }
        if (s[i].size() < mins.size()) {
            mins = s[i];
        }
    }
    cout << maxs << endl << mins << endl;
    return 0;
}