//
// Created by Emme.Kwok on 2025/12/21.
//
#include<iostream>
#include<iomanip>
using namespace std;

const int m[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
          s[] = {0, 2, 5, 5, 1, 3, 6, 1, 4, 0, 2, 5, 0};


int main() {
    // int n;
    // cin >> n;
    // cout << "MON TUE WED THU FRI SAT SUN" << endl;
    // int t = 0;
    // for (int i = 1; i <= s[n]; i++) {
    //     cout << "    ";
    //     t++;
    // }
    // for (int i = 1; i <= m[n]; i++, t++) {
    //     if (t == 7) {
    //         t = 0;
    //         cout << endl;
    //     }
    //     cout << setw(3) << i << " ";
    // }
    cout << sizeof('a') << endl;
    cout << sizeof(char) << endl;
    cout << sizeof(int) << endl;
    return 0;
}