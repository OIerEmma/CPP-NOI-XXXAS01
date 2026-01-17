//
// Created by Emma on 2025/8/11.
//
#include<iostream>
#include<climits>
using namespace std;

int main() {
    int n, num;
    cin >> n;
    int maxx = INT_MIN, minn = INT_MAX, maxidx = -1, minidx = -1;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        if (maxx < num) {
            maxx = num;
            maxidx = i;
        }
        if (minn > num) {
            minn = num;
            minidx = i;
        }
    }
    cout << "max=" << maxx << " (" << maxidx << ")" << endl;
    cout << "min=" << minn << " (" << minidx << ")" << endl;
    return 0;
}
