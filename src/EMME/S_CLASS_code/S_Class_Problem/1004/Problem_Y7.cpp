//
// Created by Emma on 2025/7/7.
//
#include<iostream>
#include<cmath>
using namespace std;

int datacge_to_ten(int num, int data) {
    string s = to_string(num);
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        ans += (s[i] - 48) * int(pow(data, s.size() - i - 1));
    }
    return ans;
}

int main() {
    int a, b, r, i;
    cin >> a >> b >> r;
    for (i = 2; i <= 40; i++) {
        if (a * b == datacge_to_ten(r, i)) {
            cout << i << endl;
            break;
        }
    }
    if (i == 41) {
        cout << 0 << endl;
    }
    return 0;
}