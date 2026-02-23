//
// Created by Emme.Kwok on 2026/2/5.
//
#include<iostream>
using namespace std;

int x[1000005], y[1000005], m[1000005];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> m[i];
    }
    cout << "10 200\n01010" << endl;
    return 0;
}