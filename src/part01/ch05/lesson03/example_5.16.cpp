//
// Created by Emma on 2025/2/8.
//
#include<iostream>
using namespace std;

int main() {
    string s;
    bool flag = false;

    getline(cin, s);

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            if (flag == false) {
                cout << s[i];
                flag = true;
            }
        } else {
            cout << s[i];
            flag = false;
        }
    }
    cout << endl;
    return 0;
}
