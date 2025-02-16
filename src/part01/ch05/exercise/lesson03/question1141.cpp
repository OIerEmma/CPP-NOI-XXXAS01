//
// Created by Emma on 2025/2/16.
//
#include<iostream>
using namespace std;

int main() {
    string n;
    cin >> n;
    if (n.substr(n.size() - 2, 2) == "er" || n.substr(n.size() - 2, 2) == "ly") {
        n.erase(n.size() - 2, 2);
    } else if (n.substr(n.size() - 3, 3) == "ing") {
        n.erase(n.size() - 3, 3);
    }
    cout << n << endl;
    return 0;
}