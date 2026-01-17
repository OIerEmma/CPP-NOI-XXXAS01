//
// Created by Amy.Kwok on 2025/12/18.
//
#include<iostream>
using namespace std;

int main() {
    int a[1001],n,ma = -1;
    cin >> n;
    for (int i = 1;i <=n;i++)
        cin >> a[i];
    for (int i = 1;i <= n - 1;i++) {
        if (a[i] - a[i+1] > ma) {
            if (a[i]-a[i+1] >ma)
                ma = a[i]-a[i+1];
        }
        else if (a[i+1] - a[i] > ma) {
                ma = a[i+1]-a[i];
        }
    }
    cout << ma << endl;
    return 0;
}