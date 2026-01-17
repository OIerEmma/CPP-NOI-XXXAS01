//
// Created by Emme.Kwok on 2025/9/21.
//
#include<iostream>
using namespace std;

const int MAXN = 500001;
int prime[MAXN];
bool isnp[MAXN]; // is not prime: 不是素数
void init(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (!isnp[i]) {
            for (int j = i * i; j <= n; j += i) {
                isnp[j] = true;
            }
        }
    }
}

int to_int(string s) {
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        ans = ans * 10 + (s[i] - 48);
    }
    return ans;
}

int main() {
    int n;
    init(MAXN - 1);
    int cnt = 0;
    for (int i = 2; i <= MAXN-1; i++) {
        if (!isnp[i]) {
            prime[++cnt] = i;
        }
    }
    string line;
    while (getline(cin, line)) {
        cout << prime[to_int(line)] << endl;
    }
    return 0;
}
