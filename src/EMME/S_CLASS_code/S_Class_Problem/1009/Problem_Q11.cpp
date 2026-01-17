//
// Created by Emma on 2025/7/28.
//
#include<iostream>
using namespace std;
typedef long long l;

string m_data(l data, l num) {
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
    l m, a, b;
    for (; ;) {
        cin >> m;
        if (m == 0) {
            break;
        }
        cin >> a >> b;
        cout << m_data(m, a + b) << endl;
    }
    return 0;
}