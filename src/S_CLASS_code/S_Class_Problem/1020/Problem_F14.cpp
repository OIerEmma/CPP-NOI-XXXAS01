//
// Created by Emma on 2025/8/8.
//
#include<iostream>
using namespace std;

int presum[1000010];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n / 2 + 1; i++) {
        presum[i] += presum[i - 1] + i;
    }
    for (int i = 1; i <= n / 2 + 1; i++) {
        for (int j = i + 1; j <= n / 2 + 1; j++) {
            if (presum[j] - presum[i - 1] > n) {
                break;
            }
            if (presum[j] - presum[i - 1] == n) {
                cout << i << " " << j << endl;
                break;
            }
        }
    }
    return 0;
}
