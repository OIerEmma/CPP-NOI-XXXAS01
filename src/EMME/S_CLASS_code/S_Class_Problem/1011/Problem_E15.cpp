//
// Created by Emma on 2025/8/14.
//
#include<iostream>
#include<algorithm>
using namespace std;

string arr[101];

bool cmp(string x, string y) {
    if (x.size() != y.size()) {
        return x.size() < y.size();
    }
    return x < y;
}

int main() {
    int n;
    while(cin >> n) {
        for (int i = 0; i < n; i ++) {
            cin >> arr[i];
        }
        sort(arr, arr + n, cmp);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << endl;
        }
    }
    return 0;
}