//
// Created by Emma on 2025/7/13.
//
#include<iostream>
using namespace std;

int main() {
    string a, b;
    while(cin >> a && cin >> b) {
        long long ans = 0;
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < b.size(); j++) {
                ans += (a[i] - 48) * (b[j] - 48);
            }
        }
        cout << ans << endl;
    }
    return 0;
}