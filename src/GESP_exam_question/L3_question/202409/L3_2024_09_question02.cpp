//
// Created by Emme.Kwok on 2025/12/21.
//
#include<iostream>
using namespace std;

bool ish(string s) {
    for (int i = 0, j = (int)s.size() - 1; i <= j; i++, j--) {
        if (s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    string s;
    for (int i = 1; i <= n; i++) {
        bool flag = false;
        cin >> s;
        getchar();
        if (s.size() <= 3) {
            cout << "No" << endl;
            continue;
        }
        for (int j = 2; j <= s.size() - 2; j++) {
            string s1 = s.substr(0, j), s2 = s.substr(j, s.size() - j + 1);
            // cout << s1 << " " << ish(s1) << endl;
            // cout << s2 << " " << ish(s2) << endl;
            if (ish(s1) && ish(s2)) {
                cout << "Yes" << endl;
                flag = true;
                break;
            }
            // cout << endl;
        }
        if (!flag) {
            cout << "No" << endl;
        }
        // cout << "------------------------------------------" << endl;
    }
    return 0;
}