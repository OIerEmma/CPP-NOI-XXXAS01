//
// Created by Emma on 2025/2/16.
//
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    if (a.find(b) != -1) {
        cout << b << " is substring of " << a;
    } else if (b.find(a) != -1) {
        cout << a << " is substring of " << b;
    } else {
        cout << "No substring";
    }
    return 0;
}
