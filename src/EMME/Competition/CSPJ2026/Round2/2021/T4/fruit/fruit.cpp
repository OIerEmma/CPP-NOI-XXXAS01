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
    list<int> a;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        a.push_back(x);
    }
    while (!a.empty()) {
        int last = 0, i = 1;
        auto it = a.begin(), d = a.begin();
        while (it != a.end()) {
            if (it == a.begin()) {
                last = *it;
            } else if (*it != last) {
                a.erase(d);
                d = it;
                cout << i << " ";
            }
            it++; i++;
        }
        cout << "\n";
    }
    return 0;
}