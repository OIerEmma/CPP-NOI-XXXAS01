//
// Created by Emma on 2025/6/14.
//
#include<iostream>
using namespace std;

string s[1010];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int t = 1; t <= n; t++) {
        bool tw = true, e = true, te = true, si = true;
        for (int i = 0; i < s[t].size(); i++) {
            char c = s[t][i];
            if (c > 'F') {
                tw = e = te = si = false;
            } else if (c >= 'A') {
                tw = e = te = false;
            } else if (c >= '8' && c <= '9') {
                tw = e = false;
            } else if (c >= '2') {
                tw = false;
            }
        }
        cout << tw << " " << e << " " << te << " " << si << endl;
    }
    return 0;
}