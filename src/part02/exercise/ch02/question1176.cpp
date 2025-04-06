//
// Created by Emma on 2025/4/5.
//
#include<iostream>
using namespace std;

int main() {
    int k, n, maxn;
    scanf("%d %d", &n, &k);
    string num[n], temp2;
    double score[n], temp;
    for (int i = 0; i < n; i++) {
        cin >> num[i] >> score[i];
    }
    for (int i = 0; i < n; i++) {
        maxn = i;
        for (int j = i; j < n; j++) {
            if (score[j] > score[maxn]) {
                maxn = j;
            }
        }
        if (maxn != i) {
            temp = score[maxn];
            score[maxn] = score[i];
            score[i] = temp;
            temp2 = num[maxn];
            num[maxn] = num[i];
            num[i] = temp2;
        }
    }
    cout << num[k - 1] << " " << score[k - 1];
    return 0;
}
