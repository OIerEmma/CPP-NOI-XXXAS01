//
// Created by Emma on 2025/8/2.
//
#include<iostream>
using namespace std;

string s[70];
int find8(string str) {
    int ans = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '8') {
            ans++;
        }
    }
    return ans;
}

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        ans += find8(s[i]);
    }
    cout << ans << endl;
    return 0;
}