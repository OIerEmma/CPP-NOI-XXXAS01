//
// Created by Emma on 2025/7/12.
//
#include<iostream>
using namespace std;

int main() {
    string r, s;
    cin >> r;
    getchar();
    while(getline(cin, s)) {
        while (s.find("In") != string::npos || s.find("IN") != string::npos ||
            s.find("iN") != string::npos || s.find("in") != string::npos) {
            if (s.find("In") != string::npos) {
                s.erase(s.find("In"), 2);
            }
            else if (s.find("IN") != string::npos) {
                s.erase(s.find("IN"), 2);
            }
            else if (s.find("iN") != string::npos) {
                s.erase(s.find("iN"), 2);
            }
            else if (s.find("in") != string::npos) {
                s.erase(s.find("in"), 2);
            }
        }
        while (s.find(' ') != string::npos) {
            s.erase(s.find(' '), 1);
        }
        cout << s << endl;
    }
    return 0;
}