//
// Created by Emma on 2025/7/28.
//
#include<iostream>
#include<cmath>
using namespace std;
typedef long long l;

l to_l(string s) {
    l ans = 0;
    for (int i = 0; i < s.size(); i++) {
        ans = ans * 10 + (s[i] - 48);
    }
    return ans;
}

string to_tendata(l nowdata, string num) {
    l ans = 0;
    for (int i = 0; i < num.size(); i++) {
        if (!isdigit(num[i])) {
            ans += l(pow(nowdata, num.size() - i - 1) * (10 + (num[i] - 'A')));
        } else {
            ans += l(pow(nowdata, num.size() - i - 1) * (num[i] - 48));
        }
    }
    return to_string(ans);
}

string b_data(l data, l num) {
    string ans;
    while (num >= data) {
        if (num % data >= 10) ans = to_string('A' + (num % data - 10)) + ans;
        else ans = to_string(num % data) + ans;
        num /= data;
    }
    if (num % data >= 10) ans = to_string('A' + (num % data - 10)) + ans;
    else ans = to_string(num % data) + ans;
    return ans;
}

int main() {
    l a, b;
    string n;
    while (cin >> a && cin >> n && cin >> b) {
        string ans = to_tendata(a, n);
        if (b == 10) {
            cout << ans << endl;
        } else {
            cout << b_data(b, to_l(ans)) << endl;
        }
    }
    return 0;
}