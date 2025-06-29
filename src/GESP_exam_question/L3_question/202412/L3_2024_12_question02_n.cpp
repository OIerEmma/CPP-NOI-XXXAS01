//
// Created by Emma on 2025/6/25.
//
#include<iostream>
using namespace std;

int main() {
    string s0[5] = {".....", ".***.", ".***.", ".***.", "....."};
    string s1[5] = {"****.", "****.", "****.", "****.", "****."};
    string s2[5] = {".....", "****.", ".....", ".****", "....."};
    string s3[5] = {".....", "****.", ".....", "****.", "....."};
    string n;
    cin >> n;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < n.size(); j++) {
            if (n[j] == '0') {
                cout << s0[i];
            } else if (n[j] == '1') {
                cout << s1[i];
            } else if (n[j] == '2') {
                cout << s2[i];
            } else if (n[j] == '3') {
                cout << s3[i];
            }
        }
        cout << endl;
    }
    return 0;
}