//
// Created by Emma on 2025/7/8.
//
#include<iostream>
using namespace std;

int a[110], b[1010];

int main() {
    int n;
    cin >> n;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        b[num]++;
    }
    int cnt = 0;
    for (int i = 0; i < 1000; i++) {
        if (b[i] != 0) {
            a[cnt++] = i;
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++) {
        cout << a[i] << " ";
    }
    return 0;
}