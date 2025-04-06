//
// Created by Emma on 2025/3/2.
//
#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

void combinationSum(vector<int>& nums, int k, int start, int currentSum, int& count) {
    if (k == 0) {
        if (isPrime(currentSum)) {
            count++;
        }
        return;
    }
    for (int i = start; i < nums.size(); ++i) {
        combinationSum(nums, k - 1, i + 1, currentSum + nums[i], count);
    }
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    int count = 0;
    combinationSum(nums, k, 0, 0, count);
    cout << count << endl;
    return 0;
}