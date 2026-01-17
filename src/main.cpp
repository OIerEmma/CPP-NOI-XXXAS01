//
// Created by Emma on 2024/11/10.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(nullptr)); // 初始化种子
    int num = 1 + rand() % 100; // 生成 1 到 100 之间的随机数
    std::cout << "1-100 随机数: " << num << endl;
    return 0;
}
/*
 * 推送远程GIT仓库步骤：
 * 1. 编写完代码之后, 打开 Terminal
 * 1.1 输入命令：git diff (查看本地变更内容, 退出请按字母q)
 * 2. 输入命令：git add . (把本地文件暂存到本地仓库的暂存区域)
 * 3. 输入命令：git commit -m ' 本次提交内容注释,如"添加例题5" ' (把本地文件提交到本地仓库)
 * 4. 输入命令：git push (把本地仓库代码推送到远程仓库)
 */

