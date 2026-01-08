class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int x = nums1.size(), m = nums2.size();
        vector<vector<int>>dp(x,vector<int>(m,-1e9));
        for(int i = 0; i < x; i++) {
            for (int j = 0; j < m; j++) {
                int pro = nums1[i] * nums2[j];
                if(i>0 && j > 0) {
                    dp[i][j] = max(dp[i][j], pro + dp[i-1][j-1]);
                }
                dp[i][j] = max(pro, dp[i][j]);
                if (i > 0) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j]);
                }
                if (j > 0) {
                    dp[i][j] = max(dp[i][j], dp[i][j-1]);
                }
            }
        }
        return dp[x-1][m-1];
    }
};