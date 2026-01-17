//
// Created by Emma on 2025/2/16.
//
#include<iostream>
using namespace std;

int main() {
    string n[200], line;
    string maxstr, minstr;
    int i, j = 0, pos = 0;
    getline(cin, line);
    for (i = 0; i < line.size(); i++) {
        if (line[i] == ' ' || line[i] == ',') {
            n[j++] = line.substr(pos, i - pos);
            while (line[++i] == ' ' || line[i] == ',');
            pos = i--;
        }
    }
    n[j++] = line.substr(pos, i - pos);
    maxstr = n[0], minstr = n[0];
    for (i = 1; i < j; i++) {
        if (maxstr.size() < n[i].size()) {
            maxstr = n[i];
        }
        if (minstr.size() > n[i].size()) {
            minstr = n[i];
        }
    }
    cout << maxstr << endl << minstr << endl;
    return 0;
}
