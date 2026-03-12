//
// Created by Emme.Kwok on 2026/2/4.
//
#include<iostream>
using namespace std;

int arr[100005], n;

void toheap(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        toheap(arr, n, largest);
    }
}

void hsort(int arr[]) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        toheap(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        toheap(arr, i, 0);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    hsort(arr);
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    return 0;
}