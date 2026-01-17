//
// Created by Emma on 2025/2/16.
//
#include<iostream>
using namespace std;

int main() {
    int n;
    char ans[20];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        // scanf("%s", ans);
        cin >> ans;
        int len = strlen(ans);
        if (isalpha(ans[0])) {
            ans[0] = char(toupper(ans[0]));
        }
        for (int j = 1; j < len; j++) {
            if (isalpha(ans[j])) {
                ans[j] = (char)tolower(ans[j]);
            }
        }
       cout << ans << endl;
    }
    return 0;
}
