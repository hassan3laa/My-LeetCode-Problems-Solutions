class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>closest(n);
        for(int i=0;i<n;i++){
            if(i==0) closest[i] = 1;
            else if(i == n-1) closest[i] = n-2;
            else {
                int left = nums[i] - nums[i-1];
                int right = nums[i+1] - nums[i];
                if(left <= right) closest[i] = i-1;
                else closest[i] = i+1;
            }
        }
        vector<long long> rightCost(n, 0);
        for (int i = 0; i < n - 1; i++) {
            if (closest[i] == i + 1) rightCost[i] = 1;
            else rightCost[i] = nums[i + 1] - nums[i];
        }
        vector<long long> leftCost(n,0);
        for(int i=1;i<n;i++) {
            if(closest[i] == i-1) leftCost[i] = 1;
            else leftCost[i] = nums[i] - nums[i-1];
        }
        vector<long long> prefR(n,0);
        for(int i=1;i<n;i++){
            prefR[i] = prefR[i-1] + rightCost[i-1];
        }
        vector<long long> prefL(n,0);
        for(int i=n-2; i>=0; i--) {
            prefL[i] = prefL[i+1] + leftCost[i+1];
        }
        vector<int> ans;
        for(auto&q : queries) {
            int l=q[0], r=q[1];
            if(l < r) ans.push_back(prefR[r] - prefR[l]);
            else ans.push_back(prefL[r] - prefL[l]);
        }
        return ans;
    }
};