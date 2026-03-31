//
// Created by Geek.Kwok on 2026/3/31.
//
#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(const int x) : val(x), left(nullptr), right(nullptr) {}
};

class NaryTreeNode {
public:
    int val;
    vector<NaryTreeNode*> children;
};

/*
int main() {
    // 可以这样构建一棵二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    // 构建出来的二叉树是这样的：
    //       1
    //      / \
    //     2   3
    //    /   / \
    //   4   5   6
    return 0;
}
*/