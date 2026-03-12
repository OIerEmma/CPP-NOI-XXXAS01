//
// Created by Emma on 2025/2/19.
//
#include<iostream>
using namespace std;

int main() {
    int k, cnt = 0;
    string input;
    cin >> k >> input;
    char ch = input[0];
    for (int i = 0; i < input.size(); i++) {
        if (ch != input[i]) {
            ch = input[i];
            cnt = 0;
        }
        cnt++;
        if (cnt >= k) {
            cout << ch << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
