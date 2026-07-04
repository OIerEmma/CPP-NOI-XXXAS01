//
// Created by Geek.Kwok on 5/15/26.
//
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, target;
    cin >> n;
    vector<int> m(n);
    for (int i = 1; i <= n; i++)
        cin >> m[i];
    cin >> target;
    sort(m.begin(), m.end());
    auto it = lower_bound(m.begin(), m.end(), target);
    if (it == m.end()) cout << -1 << endl;
    else cout << *it << endl;

    /* ---------------------
    int k;
    cin >> k;
    while (k--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        // 贪心+二分
        vector<int> t1, t2;
        for (int x: arr) {
            // 最长上升子序列
            auto it1 = lower_bound(t1.begin(), t1.end(), x);
            if (it1 == t1.end()) t1.push_back(x);
            else *it1 = x;

            // 最长下降子序列
            auto it2 = upper_bound(t2.begin(), t2.end(), x, greater<int>());
            if (it2 == t2.end()) t2.push_back(x);
            else *it2 = x;
        }

        cout << max(t1.size(), t2.size()) << endl;
    }*/

    int n, target;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> target;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    // auto it = lower_bound(a.begin(), a.end(), target);
    auto it = upper_bound(a.begin(), a.end(), target);
    if (it == a.end()) cout << -1 << endl;
    else cout << *it << endl;

    return 0;
}

/**
3
8
300 207 155 299 298 170 158 65
8
65 158 170 298 299 155 207 300
10
2 1 3 4 5 6 7 8 9 10

6
6
9
 */