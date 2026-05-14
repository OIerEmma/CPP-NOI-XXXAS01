//
// Created by Geek.Kwok on 2026/5/14.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 输入
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    // 贪心+二分
    vector<int> tails;
    for (int x: arr) {
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) tails.push_back(x);
        else *it = x;
    }
    cout << n - tails.size() << endl;
    return 0;
}