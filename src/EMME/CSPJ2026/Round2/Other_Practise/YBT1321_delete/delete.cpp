//
// Created by Emme.Kwok on 2026/9/25.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    string n;
    int s;
    cin >> n >> s;
    for (int i = 1; i <= s; i++) {
        bool flag = false;
        for (int j = 0; j < n.size() - 1; j++)
            if (n[j] > n[j + 1]) {
                n.erase(j, 1);
                flag = true;
                break;
            }
        if (!flag) n.erase(n.size() - 1, 1);
    }
    while (n[0] == '0') n.erase(0, 1);
    if (n.empty()) cout << "0\n";
    else cout << n << endl;
    return 0;
}