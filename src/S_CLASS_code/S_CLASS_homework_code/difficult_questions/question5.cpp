//
// Created by Emma on 2025/2/3.
//
#include<iostream>
using namespace std;

int main() {
    int ming = 0, wang = 0, k, m_num, w_num;
    int small, big;
    bool w_is_big;
    scanf("%d\n", &k);
    for (int i = 1; i <= k; i++) {
        scanf("%d %d", &w_num, &m_num);
        if (w_num > m_num) {
            big = w_num;
            w_is_big = true;
            small = m_num;
        } else {
            big = m_num;
            w_is_big = false;
            small = w_num;
        }

        if (big == 20 && (small == 5 || small == 10)) {
            if (w_is_big) {
                ming += 10;
            } else {
                wang += 10;
            }
        } else {
            if (w_is_big) {
                wang += m_num - w_num;
            } else {
                ming += m_num - w_num;
            }
        }
        printf("%d %d", wang, ming);
        return 0;
    }
}
