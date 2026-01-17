//
// Created by Emma on 2025/2/12.
//
#include<iostream>
#include<cstring>
using namespace std;

int main() {
    string orginal = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char ans[27];
    string temp = "A";
    int n;
    scanf("%d", &n);
    memset(ans, 0, sizeof(ans));
    if (n % 26 == 0) {
        cout << orginal << endl;
        return 0;
    } else {
        // n %= 26; // 2
        // // 内容替换
        // for (int i = 0; i < orginal.size(); i ++) {
        //     // if (orginal[i] + n > 'Z') {
        //     //     ans[i] = char(orginal[i] + n - 26) ;
        //     // }
        //     ans[i] = char(65 + ((orginal[i] - 65) + n) % 26);
        // }

        for (int i = 0; i < 26; i ++) {
            int j = (i + n) % 26;
            cout << char(j + 'A');
        }
        cout << endl;
        // 移动位置
        // for (int i = 1; i <= n; i++) {
        //     orginal = orginal.substr(1);
        //     orginal += temp;
        //     temp[0] += 1;
        // }
        // cout << ans << endl;
        return 0;
    }
}