//
// Created by Emma on 2025/8/11.
//
#include<iostream>
#include<climits>
using namespace std;

int main() {
    int n, num;
    cin >> n;
    int minn = INT_MAX;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        minn = min(minn, num);
    }
    cout << minn << endl;
    return 0;
}