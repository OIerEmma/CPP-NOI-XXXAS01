//
// Created by Emme.Kwok on 2026/1/25.
//
#include<iostream>
#include<string>
using namespace std;

int main() {
    string n;
    int s;
    cin >> n >> s;
    for (int i = 1; i <= s; i++) {
        bool flag = false;
        for (int j = 0; j < n.size() - 1; j++) {
            if (n[j] > n[j + 1]) {
                n.erase(j, 1);
                flag = true;
                break;
            }
        }
        if (!flag) {
            n.erase(n.size() - 1, 1);
        }
    }
    int i = 0;
    while (n[i] == '0') i++;
    if (i == n.size()) {
        cout << 0;
    } else {
        cout << n.substr(i, n.size() - i);
    }
    return 0;
}