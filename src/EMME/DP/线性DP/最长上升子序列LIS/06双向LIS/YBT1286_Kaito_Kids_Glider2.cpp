//
// Created by Emme.Kwok on 2026/6/1.
//
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, k;
    cin >> k;
    while (k--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> tails, tails2;
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(tails.begin(), tails.end(), a[i]);
            if (it == tails.end()) tails.push_back(a[i]);
            else *it = a[i];
            auto it2 = upper_bound(tails2.begin(), tails2.end(), a[i], greater<int>());
            if (it2 == tails2.end()) tails2.push_back(a[i]);
            else *it2 = a[i];
        }
        cout << max(tails.size(), tails2.size()) << endl;
    }
    return 0;
}