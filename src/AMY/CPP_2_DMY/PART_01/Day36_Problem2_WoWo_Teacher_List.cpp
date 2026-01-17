//
// Created by Amy on 2025/10/22.
//
#include<iostream>
using namespace std;

int main() {
    int n;
    int sum=0;
    int a[1001];
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        if (a[i] > a[n]) {
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}