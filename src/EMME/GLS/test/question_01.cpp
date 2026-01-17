//
// Created by Emme.Kwok on 2025/10/13.
//
#include<iostream>
#include<string>
using namespace std;

int main() {
    long long m, n;
    int ans = 0;
    cin >> m >> n;
    for (long long i = m; i <= n; i++) {
        string s = to_string(i);
        if (s.find('3') != string::npos || s.find('7') != string::npos) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}