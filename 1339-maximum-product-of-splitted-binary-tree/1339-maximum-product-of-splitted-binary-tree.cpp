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
    long long sum =0, ans=0;
    const int mod = 1e9+7;

    long long summ (TreeNode* node) {
        if (!node) return 0;
        return node->val + summ(node->left) + summ(node->right);
    }
    

    long long dfs (TreeNode* node) {
        if (!node) return 0;
        long long left = dfs(node->left);
        long long right=dfs(node->right);
        long long sub = node->val + left+right;

        long long pro = sub * (sum - sub);
        ans = max(ans,pro);
        return sub;
    }


    int maxProduct(TreeNode* root) {
        sum = summ(root);
        dfs(root);
        return ans%mod;
    }
};