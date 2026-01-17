//
// Created by Emma on 2025/7/2.
//
#include <iostream>
using namespace std;

int x[1000010];

int main() {
    int n;
    cin >> n;
    int temp = 1, maxx = 1;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        if (x[i] == x[i - 1]) {
            temp++;
        } else {
            temp = 1;
        }
        if (temp > maxx) {
            maxx = temp;
        }
    }
    printf("%d\n", maxx);
    return 0;
}
