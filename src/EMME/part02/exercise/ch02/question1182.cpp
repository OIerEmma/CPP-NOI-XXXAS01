//
// Created by Emma on 2025/4/13.
//
#include<iostream>
#include<algorithm>
using namespace std;
double num[40], male[40], female[40];
string sex[40];

bool cmp(double x, double y) {
    return x < y;
}

bool cmp2(double x, double y) {
    return x > y;
}

int main() {
    int cnt1 = 0, cnt2 = 0, n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> sex[i] >> num[i];
        if (sex[i] == "male") {
            male[cnt1++] = num[i];
        } else {
            female[cnt2++] = num[i];
        }
    }
    sort(male, male + cnt1, cmp);
    sort(female, female + cnt2, cmp2);
    for (int i = 0; i < cnt1; i++) {
        printf("%.2lf ", male[i]);
    }
    for (int i = 0; i < cnt2; i++) {
        printf("%.2lf ", female[i]);
    }
    return 0;
}
