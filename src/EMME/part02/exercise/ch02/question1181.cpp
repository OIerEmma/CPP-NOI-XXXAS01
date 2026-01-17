//
// Created by Emma on 2025/4/13.
//
#include<iostream>
#include<algorithm>
using namespace std;
int num[10], odd[10], even[10];

bool cmp(int x, int y) {
    return x > y;
}

bool cmp2(int x, int y) {
    return x < y;
}

int main() {
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < 10; i++) {
        scanf("%d", &num[i]);
        if (num[i] % 2 == 0) {
            even[cnt1++] = num[i];
        } else {
            odd[cnt2++] = num[i];
        }
    }
    sort(odd, odd + cnt2, cmp);
    sort(even, even + cnt1, cmp2);
    for (int i = 0; i < cnt2; i++) {
        printf("%d ", odd[i]);
    }
    for (int i = 0; i < cnt1; i++) {
        printf("%d ", even[i]);
    }
    return 0;
}
