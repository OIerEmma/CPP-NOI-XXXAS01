//
// Created by Emma on 2025/4/6.
//
#include<iostream>
using namespace std;
int a[101];

void qsort(int left, int right) {
    int i, j, mid, temp;
    i = left;
    j = right;
    mid = a[(left + right) / 2];
    do {
        while (a[i] < mid) i++;
        while (a[j] > mid) j--;
        if (i <= j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);
    if (left < j) {
        qsort(left, j);
    }
    if (i < right) {
        qsort(i, right);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    qsort(0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}