//
// Created by Emma on 2025/3/14.
//
#include<iostream>
using namespace std;

double solve() {
    string a;
    cin >> a;
    if (a[0] == '+') {
        return solve() + solve();
    }
    if (a[0] == '-')
        return solve() - solve();
    if (a[0] == '*')
        return solve() * solve();
    if (a[0] == '/')
        return solve() / solve();
    return stod(a);
}

int main() {
    printf("%f\n", solve());
    return 0;
}
