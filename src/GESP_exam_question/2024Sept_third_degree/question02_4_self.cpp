//
// Created by Emma on 2025/2/10.
//
#include<iostream>
using namespace std;

bool backstr(string a) {
    bool ans = false;
    for (int i = 0; i < a.size() / 2; i++) {
        if (a[i] == a[a.size() - (i + 1)]) {
            ans = true;
        } else {
            ans = false;
            break;
        }
    }
    return ans;
}

int main() {
    string a;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        bool flag = false;
        cin >> a;
        for (int split = 2; split < a.size() - 1; split++) {
            string part_one = a.substr(0, split);
            string part_two = a.substr(split, a.size() - split);
            if (backstr(part_one) && backstr(part_two)) {
                flag = true;
                printf("Yes\n");
                break;
            }
        }
        if (!flag) {
            printf("No\n");
        }
    }
    return 0;
}
