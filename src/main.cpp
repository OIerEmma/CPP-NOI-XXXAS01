//
// Created by Emma on 2024/11/10.
//
#include<iostream>
using namespace std;

int main() {
    int a[] = {0, 1, 2, 3, 4, 5};
    for (int i = 1; i <= 5; i++) {
        swap(a[i], a[5 - i + 1]);
    }
    for (int j = 1; j <= 5; j++) {
        cout << a[j] << endl;
    }
    return 0;
}
/**
 * 推送远程GIT仓库步骤：
 * 1. 编写完代码之后, 打开 Terminal
 * 1.1 输入命令：git diff (查看本地变更内容, 退出请按字母q)
 * 2. 输入命令：git add . (把本地文件暂存到本地仓库的暂存区域)
 * 3. 输入命令：git commit -m ' 本次提交内容注释,如"添加例题5" ' (把本地文件提交到本地仓库)
 * 4. 输入命令：git push (把本地仓库代码推送到远程仓库)
 */
// #include <iostream>
// using namespace std;
//
// bool isLeapYear(int year) {
//     if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
//         return true;
//     }
//     return false;
// }
//
// int main() {
//     int d, m = 0;
//     scanf("%d", %d);
//     while(m <= 480) {
//         m++;
//     }
//     return 0;
// }