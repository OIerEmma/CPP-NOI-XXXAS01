//
// Created by Emma on 2025/1/20.
//
#include<iostream>
using namespace std;

int main() {
    string a;
    cin >> a;
    bool flag = true;
    for (int i = 0; i <= (a.size()-1) / 2; i++) {
        if (a[i] != a[a.size() - 2 - i]) {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
