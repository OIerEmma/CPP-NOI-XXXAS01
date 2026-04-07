//
// Created by Geek.Kwok on 2026/4/1.
//
#include <iostream>
#include <climits>
using namespace std;

/** 在实际的算法问题中，DFS 算法常用来穷举所有路径，L03_BFS 算法常用来寻找最短路径。 */

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    // 记录最小深度（根节点到最近的叶子节点的距离）
    int minDepthValue = INT_MAX;
    // 记录当前遍历到的节点深度
    int currentDepth = 0;

public:
    int minDepth(const TreeNode* root) {
        if (root == nullptr) return 0;
        // 从根节点开始 DFS 遍历
        traverse(root);
        return minDepthValue;
    }

    void traverse(const TreeNode* root) {
        if (root == nullptr) return;

        // 前序遍历位置
        // 前序位置进入节点时增加当前深度
        currentDepth++;
        // 如果当前节点是叶子节点则更新最小深度
        if (root->left == nullptr && root->right == nullptr) {
            minDepthValue = min(minDepthValue, currentDepth);
        }

        traverse(root->left);
        traverse(root->right);

        // 后续位置离开节点时则减少当前深度
        currentDepth--;
    }
};

int main() {

    return 0;
}