//
// Created by Emma on 2025/1/19.
//
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    double people[n + 1];
    people[0] = n;
    double max, max_x, min, min_x, sum = 0.0;
    for (int i = 1; i <= n; i++) {
        cin >> people[i];
        if (i == 1) {
            max = people[1];
            min = people[1];
        } else {
            if (people[i] > max) {
                max = people[i];
                max_x = i;
            }
            if (people[i] < min) {
                min = people[i];
                min_x = i;
            }
        }
        sum += people[i];
    }
    double average = (sum - max - min) / (n - 2) * 1.0;
    double error = 0.0;
    int temp = 0;
    for (int i = 1; i <= n; i++) {
        if (i == max_x || i == min_x) continue;
        if (abs(people[i] - average) > error) error = abs(people[i] - average);
    }
    printf("%.2lf %.2lf", average, error);
    return 0;
}
