//
// Created by Emma on 2025/7/29.
//
#include<iostream>
using namespace std;

string s[110];

int main() {
    string line, a, b;
    while(getline(cin, line)) {
        cin >> a; getchar();
        cin >> b; getchar();
        line += " ";
        int cnt = 1, last = 0;
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == ' ') {
                s[cnt++] = line.substr(last, i - last);
                last = i + 1;
            }
        }
        for (int i = 1; i < cnt; i++) {
            if (s[i] == a) {
                s[i] = b;
            }
        }
        cout << s[1];
        for (int i = 2; i < cnt; i++) {
            cout << " " << s[i];
        }
        cout << endl;
    }
    return 0;
}