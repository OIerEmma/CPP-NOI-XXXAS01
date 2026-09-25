//
// Created by Emme.Kwok on 2026/9/21.
//
class Solution {
    bool flag[505];
public:
    int findTheWinner(int n, int k) {
        int s = n, pos = 0, now = 0;
        while (s--) {
            for (int i = 1; i <= k;) {
                if (!flag[pos]) i++;
                pos = (pos + 1) % n;
            }
            now = pos == 0 ? n - 1 : pos - 1;
            flag[now] = true;
        }
        return now + 1;
    }
};