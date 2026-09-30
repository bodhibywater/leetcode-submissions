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

// BFS using queue

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> curLevel;
            
            for (int i = q.size(); i > 0; i--) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur) {
                    curLevel.push_back(cur->val);
                    q.push(cur->left);
                    q.push(cur->right);
                }
            }
            if (!curLevel.empty()) {
                res.push_back(curLevel);
            }
        }
        return res;
    }
};
