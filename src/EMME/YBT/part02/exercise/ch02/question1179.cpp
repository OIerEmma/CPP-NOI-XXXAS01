//
// Created by Emma on 2025/4/6.
//
#include<iostream>
using namespace std;

int main() {
    int n, temp1, temp2, temp3, temp4;
    scanf("%d", &n);
    int chinese[n + 1], math[n + 1], english[n + 1], num[n + 1];
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &chinese[i], &math[i], &english[i]);
        num[i] = i;
    }
    for (int i = 1, j, k; i <= n; i++) {
        for (j = i - 1; j >= 1; j--) {
            if (chinese[j] + math[j] + english[j] <= chinese[i] + math[i] + english[i]) {
                break;
            }
        }
        if (j != i - 1) {
            temp1 = chinese[i];
            temp2 = math[i];
            temp3 = english[i];
            temp4 = num[i];
            for (k = i - 1; k > j; k--) {
                chinese[k + 1] = chinese[k];
                math[k + 1] = math[k];
                english[k + 1] = english[k];
                num[k + 1] = num[k];
            }
            chinese[k + 1] = temp1;
            math[k + 1] = temp2;
            english[k + 1] = temp3;
            num[k + 1] = temp4;
        }
        while (j >= 1 && j < n && chinese[j] + math[j] + english[j] == chinese[j + 1] + math[j + 1] + english[j + 1]) {
            if (chinese[j] > chinese[j + 1] || chinese[j] == chinese[j + 1] && num[j] < num[j + 1]) {
                swap(chinese[j], chinese[j + 1]);
                swap(math[j], math[j + 1]);
                swap(english[j], english[j + 1]);
                swap(num[j], num[j + 1]);
            }
            j--;
        }
    }
    for (int i = n; i > n - 5 && i > 0; i--) {
        printf("%d %d\n", num[i], chinese[i] + math[i] + english[i]);
    }
    return 0;
}
