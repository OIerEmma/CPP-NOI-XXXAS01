//
// Created by Emma on 2025/2/10.
//
#include<iostream>
using namespace std;
string s[25];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= n - 1; i++) {
        int m = i;
        for (int j = i + 1; j <= n; j++) {
            if (s[j] < s[m]) {
                m = j;
            }
        }
        swap (s[m], s[i]);
    }
    for (int i = 1; i <= n; i++) {
        cout << s[i] << endl;
    }
    return 0;
}