//
// Created by Emme.Kwok on 2026/10/1.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 0, sum = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.size() - 1; i++)
        if (s[i] >= '0' && s[i] <= '9')
            sum += (s[i] - '0') * ++n;
    if (sum % 11 + '0' == s[s.size() - 1] ||
        sum % 11 == 10 && s[s.size() - 1] == 'X')
        cout << "Right\n";
    else {
        s[s.size() - 1] = char(sum % 11 == 10 ? 'X' : sum % 11 + '0');
        cout << s << endl;
    }
    return 0;
}