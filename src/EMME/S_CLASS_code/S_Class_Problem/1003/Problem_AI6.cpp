//
// Created by Emma on 2025/7/4.
//
#include<iostream>
using namespace std;

string s[110];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    string str;
    for (int i = 0; i < n; i++) {
        str = s[i];
        if (str[0] >= 'a' && str[0] <= 'z') {
            str[0] = char(str[0] - 32);
        }
        for (int j = 1; j < s[i].size(); j++) {
            if (str[j] >= 'A' && str[j] <= 'Z') {
                str[j] = char(str[j] + 32);
            }
        }
        s[i] = str;
    }
    for (int i = 0; i < n; i++) {
        cout << s[i] << endl;
    }
    return 0;
}
