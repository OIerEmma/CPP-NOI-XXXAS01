//
// Created by Emma on 2025/6/25.
//
#include<iostream>
using namespace std;

string s0[6] = {".....", ".***.", ".***.", ".***.", "....."},
       s1[6] = {"****.", "****.", "****.", "****.", "****."},
       s2[6] = {".....", "****.", ".....", ".****", "....."},
       s3[6] = {".....", "****.", ".....", "****.", "....."};

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '0') {
                cout << s0[i];
            } else if (s[j] == '1') {
                cout << s1[i];
            } else if (s[j] == '2') {
                cout << s2[i];
            } else {
                cout << s3[i];
            }
        }
        cout << endl;
    }
    return 0;
}