//
// Created by Emma on 2025/7/1.
//
#include<iostream>
using namespace std;

string line[510], s[1000];

string f(string str) {
    string temp = str;
    for (int i = 0, j = int(str.size() - 1); i < str.size(); i++, j--) {
        str[i] = temp[j];
    }
    return str;
}

int main() {
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++) {
        getline(cin, line[i]);
        line[i] = line[i] + " ";
    }
    for (int i = 0; i < n; i++) {
        int last = 0, cnt = 0;
        for (int j = 0; j < line[i].size(); j++) {
            if (line[i][j] == ' ') {
                s[cnt++] = line[i].substr(last, j - last);
                last = j + 1;
            }
        }
        for (int j = 0; j < cnt; j++) {
            s[j] = f(s[j]);
        }
        for (int j = 0; j < cnt; j++) {
            cout << s[j] << " ";
        }
        cout << endl;
    }
    return 0;
}