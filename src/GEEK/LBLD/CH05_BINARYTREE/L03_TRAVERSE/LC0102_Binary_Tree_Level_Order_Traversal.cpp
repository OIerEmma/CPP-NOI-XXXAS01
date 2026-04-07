//
// Created by Geek.Kwok on 2026/4/3.
//
#include <iostream>
#include <queue>
#include <vector>
#include "../L02_IMPL/TreeNode.cpp"
using namespace std;

class Solution {
public:

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> ans;
        if (root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            ans.clear();
            for (int i = 0; i < sz; i++) {
                TreeNode* cur = q.front();
                q.pop();
                ans.push_back(cur->val);
                if (cur->left != nullptr) q.push(cur->left);
                if (cur->right != nullptr) q.push(cur->right);
            }
            res.push_back(ans);
        }
        return res;
    }
};

int main() {
    return 0;
}