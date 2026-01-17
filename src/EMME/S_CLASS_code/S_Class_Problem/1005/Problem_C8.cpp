//
// Created by Emma on 2025/7/8.
//
#include<iostream>
#include<algorithm>
using namespace std;

int a[30010];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int k, num;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> num;
        cout << a[num - 1] << endl;
    }
    return 0;
}