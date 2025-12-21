//
// Created by Emme.Kwok on 2025/12/21.
//
#include<iostream>
using namespace std;

int te_to_tw(int ten) {
    string s = "";
    int ans = 0;
    if (ten == 0) {
        return 0;
    }
    while (ten != 0) {
        int temp = ten % 2;
        if (temp == 1) {
            ans++;
        }
        s = char(temp + 48) + s;
        ten /= 2;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int num, ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        ans += te_to_tw(num);
    }
    cout << ans << " ";
    if (ans % 2 == 0) {
        cout << "0" << endl;
    } else {
        cout << "1" << endl;
    }
    return 0;
}