//
// Created by Emma on 2025/8/1.
//
#include<iostream>
using namespace std;

int main() {
    long long n, king = -1, queen = -1, num;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        if (num % 2 == 0 && num > king) {
            king = num;
        }
        if (num % 2 == 1 && num > queen) {
            queen = num;
        }
    }
    cout << "Ou king=" << king << endl << "Ji queen=" << queen;
    return 0;
}