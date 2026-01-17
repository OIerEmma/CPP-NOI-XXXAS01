//
// Created by Emma on 2025/2/10.
//
#include<iostream>
using namespace std;
int a[10000];

int main() {
    //定义变量 & 输入数据
    int t, n, i, j, k, x = 0, flag = 0;
    scanf("%d", &t);
    //开始循环
    while (x < t) {
        //变量增加
        x++;
        //输入数据
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        //变量归零
        flag = 0;
        //开始判断的循环
        for (int y = 1; y <= n - 1; y++) {
            //定义变量且赋值
            int sum = 0, sum2 = 0;
            //和相加
            for (j = 0; j < y; j++) {
                sum += a[j];
            }
            for (k = j; k <= n - 1; k++) {
                sum2 += a[k];
            }
            //和进行比较
            if (sum == sum2) {
                flag++;
            }
        }
        if (flag == 1) {
            printf("Yes");
        } else {
            printf("No");
        }
    }
    return 0;
}
