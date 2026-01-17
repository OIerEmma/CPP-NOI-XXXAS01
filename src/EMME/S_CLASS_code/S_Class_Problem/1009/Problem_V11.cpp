//
// Created by Emma on 2025/7/30.
//
#include<iostream>
#include<string>
using namespace std;

int main() {
    string s;
    char c;
    while (getline(cin, s)) {
        c = (char)getchar();
        // cin >> c;
        getchar();
        size_t len = s.size();
        for (int i = 0; i < len; i++) {
            if (s[i] == c) {
                s.erase(i, 1);
                i--;
            }
        }
        cout << s << endl;
    }
    return 0;
}
