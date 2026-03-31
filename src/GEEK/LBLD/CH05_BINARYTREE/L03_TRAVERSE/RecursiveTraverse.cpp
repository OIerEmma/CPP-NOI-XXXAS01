//
// Created by Geek.Kwok on 2026/4/1.
//
#include <iostream>
#include "../L02_IMPL/TreeNode.cpp"
using namespace std;

// 二叉树的递归遍历（DFS）框架
void traverse(const TreeNode* root) {
    if (root == nullptr) return;
    // 前序位置
    traverse(root->left);
    // 中序位置
    traverse(root->right);
    // 后序位置
}

// 多叉树的递归遍历（DFS）框架
void traverse(NaryTreeNode* root) {
    if (root == nullptr) return;
    // 前序位置
    for (NaryTreeNode* child: root->children) {
        traverse(child);
    }
    // 后续位置
}

int main() {

    return 0;
}