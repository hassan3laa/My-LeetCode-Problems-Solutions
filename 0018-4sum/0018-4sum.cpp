class Solution {
public:
typedef long long ll;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
            if(i > 0 and nums[i] == nums[i-1]) continue; // skip duplicates
            for(int j=i+1; j<n; j++) {
                if (j > i+1 and nums[j] == nums[j-1]) continue; // skip duplicates
                int l = j+1, r = n-1;
                while (l < r) {
                    ll sum = 1ll * nums[i] + nums[j] + nums[l] + nums[r];
                    
                    if(sum == target) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while(l < r and nums[l] == nums[l+1])l++; // skip duplicates
                        while(l < r and nums[r] == nums[r-1])r--; // skip duplicates
                        l++, r--;
                    } else if(sum < target) {
                        l++;
                    } else r--;
                }
            }
        }
        return ans;
    }
};