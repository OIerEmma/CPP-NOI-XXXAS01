//
// Created by Geek.Kwok on 2026/4/4.
//
#include <iostream>
#include "../../../CH05_BINARYTREE/L02_IMPL/TreeNode.cpp"
using namespace std;

class Solution {
public:
    // 定义：把一棵二叉树转换成一条链表
    void flatten(TreeNode* root) {
        if (root == nullptr) return;

        // 先把左右子树转换成一条链表
        flatten(root->left);
        flatten(root->right);

        // 左子树
        TreeNode* p = root->left;
        // 左子树为空树则直接返回
        if (p == nullptr) return;

        // 把左子树转成的链表连接到 root 和 root->right 转成的链表之间
        // 1.找到左子树转成的链表的尾节点
        while (p->right != nullptr) p = p->right;
        // 2.连接左子树的链表的尾节点和右子树的链表
        p->right = root->right;
        // 3.连接根节点的右节点和左子树的链表
        root->right = root->left;
        root->left = nullptr;
    }
};

int main() {

    return 0;
}