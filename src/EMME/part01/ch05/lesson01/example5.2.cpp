//
// Created by Emma on 2025/1/12.
//
#include<iostream>
#include<iomanip>
const int n = 1000;
using namespace std;
int a[n];
int main(){
    int m;
    cin >> m;
    for (int i = 0; i <= m - 1; i++) {
        cin >> a[i];
    }
    const int temp = a[0];
    for (int i = 0; i < m - 1; i++) {
        a[i] = a[i + 1];
    }
    a[m - 1] = temp;
    for (int i = 0; i <= m - 1; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
