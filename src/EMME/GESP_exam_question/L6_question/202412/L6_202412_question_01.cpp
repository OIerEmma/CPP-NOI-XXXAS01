//
// Created by Emme.Kwok on 2026/6/24.
//
#include<iostream>
using namespace std;

const long long INF = 1e18;
int cnt;

int main() {
    int n;
    long long s;
    string str;
    cin >> n >> s >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'U') {
            if (s != 1) {
                if (cnt) cnt--;
                else s /= 2;
            }
        } else if (str[i] == 'L') {
            if (s * 2 > INF) cnt++;
            else s *= 2;
        } else {
            if (s * 2 + 1 > INF) cnt++;
            else s = 2 * s + 1;
        }
    }
    cout << s << endl;
    return 0;
}