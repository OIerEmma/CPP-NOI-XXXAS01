//
// Created by Emme.Kwok on 2026/10/21.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    list<pair<int, int>> a;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        a.push_back({x, i});
    }
    while (!a.empty()) {
        bool is = true;
        int prev = -1;
        for (auto it = a.begin(); it != a.end(); ) {
            if (is) {
                cout << (*it).second << " ";
                prev = (*it).first;
                a.erase(it++);
                is = false;
            } else if (prev != (*it).first) {
                cout << (*it).second << " ";
                prev = (*it).first;
                a.erase(it++);
            } else it++;
        }
        cout << "\n";
    }
    return 0;
}