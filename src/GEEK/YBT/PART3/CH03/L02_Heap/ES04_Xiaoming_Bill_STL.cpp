//
// Created by Geek.Kwok on 2026/4/9.
//
#include <iostream>
#include <set>
using namespace std;

multiset<int> rbt;
multiset<int>::iterator it;

int main() {
    int n, m, bill;
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n ; i++) {
        cin >> m;
        for (int j = 1; j <= m; j++) {
            cin >> bill;
            rbt.insert(bill);
        }
        cout << *rbt.begin() << " " << *(--rbt.end()) << endl;
        rbt.erase(rbt.begin());
        rbt.erase(--rbt.end());
    }
    return 0;
}