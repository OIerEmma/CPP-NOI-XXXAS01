//
// Created by Emma on 2025/1/17.
//
#include<cstring>
#include<iostream>
using namespace std;

int main() {
    int t = 0, t1 = 0;
    string s, ss;
    getline(cin, ss);
    getline(cin, s);
    const size_t l = s.size(), l2 = ss.size();
    for (int i = 0; i <= l - l2; i++) {
        for (int j = 0; j < l2; j++) {
            if (toupper(s[i + j]) != toupper(ss[j])) {
                break;
            }
            if (i > 0 && s[i - 1] != ' ') {
                break;
            }
            if (j == l2 - 1 && (s[i + j + 1] == ' ' || j + i == l)) {
                t++;
                if (t == 1) {
                    t1 = i;
                }
            }
        }
    }
    if (t == 0) {
        cout << "-1";
    } else {
        cout << t << " " << t1;
    }
    return 0;
}
