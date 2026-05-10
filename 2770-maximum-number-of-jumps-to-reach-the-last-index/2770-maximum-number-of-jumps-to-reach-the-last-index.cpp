class Solution {
public:
    vector<int>mem;
    int dfs(int i, vector<int>&nums, int target) {
        int n=nums.size();
        if(i==n-1) return 0;
        if(mem[i] != INT_MIN) return mem[i];
        int ans=-1e9;
        for(int j=i+1;j<n;j++){
            if(abs(nums[i]- nums[j]) <= target) {
                int ret= dfs(j, nums, target);
                if(ret != -1e9) {
                    ans=max(ans,ret+1);
                }
            }
        }
        return mem[i]=ans;
    }

    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        mem.assign(n,INT_MIN);
        int ans=dfs(0,nums,target);
        return ans > 0 ? ans: -1;
    }
};