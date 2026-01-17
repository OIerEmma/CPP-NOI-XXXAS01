//
// Created by Emma on 2025/7/8.
//
#include<iostream>
using namespace std;

int chinese[310], math[310], english[310], num[310];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> chinese[i] >> math[i] >> english[i];
        num[i] = i + 1;
    }
    int temp1, temp2, temp3, temp4;
    for (int i = 0, j, k; i < n; i++) {
        for (j = i - 1; j >= 0; j--) {
            if (chinese[j] + math[j] + english[j] <= chinese[i] + math[i] + english[i]) {
                break;
            }
        }
        if (j != i - 1) {
            temp1 = chinese[i];temp2 = math[i];temp3 = english[i];temp4 = num[i];
            for (k = i - 1; k > j; k--) {
                chinese[k + 1] = chinese[k];math[k + 1] = math[k];english[k + 1] = english[k];num[k + 1] = num[k];
            }
            chinese[k + 1] = temp1;math[k + 1] = temp2;english[k + 1] = temp3;num[k + 1] = temp4;
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
    for (int i = n - 1; i >= n - 5 && i >= 0; i--) {
        cout << num[i] << " " << chinese[i] + math[i] + english[i] << endl;
    }
    return 0;
}