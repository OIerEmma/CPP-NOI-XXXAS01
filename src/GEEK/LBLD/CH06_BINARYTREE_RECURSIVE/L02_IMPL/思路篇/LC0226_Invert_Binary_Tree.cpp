//
// Created by Geek.Kwok on 2026/4/4.
//
#include <iostream>
#include "../../../CH05_BINARYTREE/L02_IMPL/TreeNode.cpp"
using namespace std;

class Solution {
public:
    // 遍历视角
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;
        traverse(root);
        return root;
    }

    void traverse(TreeNode* root) {
        if (root == nullptr) return;

        // 交换左右子节点
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        traverse(root->left);
        traverse(root->right);
    }

    // 分解视角
    // 定义：将以 root 为根的这棵二叉树翻转，返回翻转后的二叉树的根节点
    TreeNode* invertTree2(TreeNode* root) {
        if (root == nullptr) return root;

        // 交换左右子节点
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        root->left = invertTree2(root->left);
        root->right = invertTree2(root->right);

        return root;
    }
};

int main() {

    return 0;
}