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

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            valToIndex[inorder[i]] = i;
        }
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    // build 函数的定义：
    // 若前序遍历数组为 preorder[preStart..preEnd],
    // 中序遍历数组为 inorder[inStart..inEnd],
    // 构造二叉树，返回该二叉树的根节点
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
        vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd) return nullptr;
        // root 节点对应的值就是前序遍历数组的第一个元素
        int rootVal = preorder[preStart];
        // 使用 map 避免循环寻找 rootVal 对应的 index
        int index = valToIndex[rootVal];
        // for (int i = inStart; i <= inEnd; i++) {
        //     // rootVal 在中序遍历数组中的索引
        //     if (inorder[i] == rootVal) {
        //         index = i; break;
        //     }
        // }
        // 左子树的节点数
        int leftSize = index - inStart;
        // 构造根节点
        TreeNode* root = new TreeNode(rootVal);
        // 递归构造左右子树
        root->left = build(preorder, preStart + 1, preStart + leftSize, inorder, inStart, index - 1);
        root->right = build(preorder, preStart + leftSize + 1, preEnd, inorder, index + 1, inEnd);

        return root;
    }
};
