/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> DFSlevelOrder(TreeNode* root) {
        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode* node, int depth) {
        if (!node) return;

        if (res.size() == depth) {
            res.push_back(vector<int>());
        }
        res[depth].push_back(node->val);
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            vector<int> lvl;
            int n = q.size();

            for (int i = n; i > 0; i--) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur) {
                    lvl.push_back(cur->val);
                    q.push(cur->left);
                    q.push(cur->right);
                }
            }
            if (!lvl.empty()) {
                res.push_back(lvl);
            }
        }
        return res;
    }
};
