//
// Created by Geek.Kwok on 2026/4/2.
//
#include <iostream>
using namespace std;

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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    int res = 0, depth = 0;

    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        traverse(root);
        return res;
    }

    void traverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        depth++;
        if (root->left == nullptr && root->right == nullptr) {
            res = max(res, depth);
        }
        traverse(root->left);
        traverse(root->right);
        depth--;
    }
};