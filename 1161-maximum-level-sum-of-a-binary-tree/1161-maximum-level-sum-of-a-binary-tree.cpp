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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 1, ans = 1;
        long long mx = LLONG_MIN;
        while (!q.empty()) {
            int s = q.size();
            long long cur=0;
            for (int i = 0; i < s; i++) {
                TreeNode* node = q.front();
                q.pop();
                cur+=node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (cur > mx) {
                mx = cur;
                ans = level;
            }
            level++;
        }   
        return ans;
    }
};