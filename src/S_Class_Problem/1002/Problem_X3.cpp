//
// Created by Emma on 2025/2/11.
//
#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int numpeople, numhouse;
    double x, y, total = 0.0;
    cin >> numhouse;
    for (int i = 1; i <= numhouse; i++) {
        cin >> x >> y >> numpeople;
        total += sqrt(x * x + y * y) / 50 * 2 + numpeople * 1 + numpeople * 0.5;
    }
    cout << ceil(total) << endl;
    return 0;
}
