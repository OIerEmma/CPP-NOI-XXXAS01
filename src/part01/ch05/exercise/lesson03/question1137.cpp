//
// Created by Emma on 2025/2/16.
//
#include<iostream>
#include<cctype>
#include<string>
using namespace std;

int main() {
    char m[50];
    string n;
    cin >> n;
    for (int i = n.size() - 1; i >= 0; i--) {
        m[n.size() - 1 - i] = n[i];
    }
    for (int i = 0; i < n.size(); i++) {
        m[i] = char(int(m[i]) + 3);
        if (!isalpha(m[i])) {
            m[i] -= 26;
        }
    }
    for (int i = 0; i < n.size(); i++) {
        if (m[i] >= 'a' && m[i] <= 'z') {
            m[i] = char(toupper(m[i]));
        } else {
            m[i] = char(tolower(m[i]));
        }
    }
    for (int i = 0; i < n.size(); i++) {
        cout << m[i];
    }
    return 0;
}
