//
// Created by Emma on 2025/3/8.
//
#include<iostream>
using namespace std;
char a[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

string changedata(int n, int m) {
    if (n < m) {
        return string(1, a[n]);
    }
    return changedata(n / m, m) + string(1, a[n % m]);
}

int main() {
    int x, m;
    cin >> x >> m;
    cout << changedata(x, m) << endl;
    return 0;
}