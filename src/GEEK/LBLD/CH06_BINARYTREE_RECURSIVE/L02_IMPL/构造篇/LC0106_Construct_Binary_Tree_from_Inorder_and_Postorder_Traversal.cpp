//
// Created by Geek.Kwok on 2026/4/5.
//
#include <iostream>
#include <unordered_map>
#include <vector>
#include "../../../CH05_BINARYTREE/L02_IMPL/TreeNode.cpp"
using namespace std;

class Solution {
public:
    // 存储 inorder 中值到索引的映射
    unordered_map<int, int> valToIndex;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i ++) {
            valToIndex[inorder[i]] = i;
        }
        return build(inorder, 0, inorder.size() - 1,
            postorder, 0, postorder.size() - 1);
    }

    // build 函数的定义：
    // 后序遍历数组为 postorder[postStart..postEnd],
    // 中序遍历数组为 inorder[inStart..inEnd],
    // 构造二叉树，返回该二叉树的根节点
    TreeNode* build(vector<int>& inorder, int inStart, int inEnd,
        vector<int>& postorder, int postStart, int postEnd) {
        if (inStart > inEnd) return nullptr;
        // root 节点对应的值就是后序遍历数组的最后一个元素
        int rootVal = postorder[postEnd];
        // rootVal 在中序遍历数组中的索引
        int index = valToIndex[rootVal];
        // 左子树的节点数
        int leftSize = index - inStart;
        // 构造根节点
        TreeNode* root = new TreeNode(rootVal);
        // 递归构造左右子树
        root->left = build(inorder, inStart, index - 1,
            postorder, postStart, postStart + leftSize - 1);
        root->right = build(inorder, index + 1, inEnd,
            postorder, postStart + leftSize, postEnd - 1);

        return root;
    }
};
