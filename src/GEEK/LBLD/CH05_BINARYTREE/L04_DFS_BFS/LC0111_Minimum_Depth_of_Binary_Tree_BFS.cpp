//
// Created by Geek.Kwok on 2026/4/1.
//
#include <iostream>
#include <climits>
#include <queue>
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
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        // 从根节点开始 L03_BFS 遍历
        queue<TreeNode*> q;
        q.push(root);
        int depth = 1; // root本身就是1层，depth初始化为1

        while (!q.empty()) {
            int sz = q.size();
            // 遍历当前层的节点
            for (int i = 0; i < sz; i++) {
                TreeNode* cur = q.front();
                q.pop();
                // 判断是否到达叶子节点
                if (cur->left == nullptr && cur->right == nullptr) {
                    return depth;
                }
                // 将下一层节点加入队列
                if (cur->left != nullptr) q.push(cur->left);
                if (cur->right != nullptr) q.push(cur->right);
            }
            // 这里增加步数
            depth++;
        }
        return depth;
    }
};

int main() {

    return 0;
}