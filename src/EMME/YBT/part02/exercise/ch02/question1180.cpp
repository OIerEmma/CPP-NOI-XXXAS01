//
// Created by Emma on 2025/4/9.
//
#include<iostream>
#include<cmath>
using namespace std;
int a[5000], num[5000];

void qsort(int* array, int* num, const int start, const int end, bool flag) {
    int i = start, j = end, mid = array[(start + end) / 2];
    do {
        if (flag) {
            while (array[i] > mid) {
                i++;
            }
            while (array[j] < mid) {
                j--;
            }
        } else {
            while (array[i] < mid) {
                i++;
            }
            while (array[j] > mid) {
                j--;
            }
        }
        if (i <= j) {
            swap(array[i], array[j]);
            if (num != nullptr) {
                swap(num[i], num[j]);
            }
            i++;
            j--;
        }
    } while (i <= j);
    if (start < j) {
        qsort(array, num, start, j, flag);
    }
    if (i < end) {
        qsort(array, num, i, end, flag);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int people = floor(m * 1.5);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &num[i], &a[i]);
    }
    qsort(a, num, 0,n - 1, true);
    for (int i = 0, j = i + 1; i < n - 1; ) {
        while (j < n && a[i] == a[j]) {
            j++;
        }
        j--;
        if (i < j) {
            qsort(num, nullptr, i, j, false);
        }
        i = j + 1;
        j = i + 1;
    }
    int score = a[people - 1], cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= score) {
            cnt++;
        }
    }
    printf("%d %d\n", score, cnt);
    for (int i = 0; i < cnt; i++) {
        printf("%d %d\n", num[i], a[i]);
    }
    return 0;
}
