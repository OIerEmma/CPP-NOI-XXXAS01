//
// Created by Amy.Kwok on 2025/12/18.
//
#include<iostream>
using namespace std;

int main() {
    int a[1001],n,ma = 0;
    cin >> n;
    for (int i = 1;i <=n;i++)
        cin >> a[i];
    for (int i = 1;i <= n - 1;i++) {
        for(int j = i + 1;j <= n; j++)
            if (a[j]-a[i] >ma)
                ma = a[j]-a[i];
    }
    cout << ma << endl;
    return 0;
}