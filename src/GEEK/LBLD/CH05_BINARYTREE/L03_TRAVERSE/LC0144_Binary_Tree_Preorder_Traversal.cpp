//
// Created by Geek.Kwok on 2026/4/2.
//
#include <iostream>
#include <vector>
#include "../L02_IMPL/TreeNode.cpp"
using namespace std;



class Solution {
public:
    vector<int> res;

    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) return res;
        traverse(root);
        return res;
    }

    void traverse(TreeNode* root) {
        if (root == nullptr) return;
        res.push_back(root->val);
        traverse(root->left);
        traverse(root->right);
    }
};

int main() {
    return 0;
}